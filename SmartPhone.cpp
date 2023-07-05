#include "SmartPhone.h"
#include <ostream>
#include <string>
#include <exception>
namespace device
{
	int SmartPhone::SetBrand(string brand)
	{
		if (brand == "") return 1;
		brand_ = brand;
		return 0;
	}
	int SmartPhone::SetModel(string model)
	{
		if (model == "") return 1;
		model_ = model;
		return 0;
	}
	int SmartPhone::SetClockRate(float cr)
	{
		if (cr <= 0) return 1;
		clock_rate_ = cr;
		return 0;
	}
	int SmartPhone::SetCores(short cores)
	{
		if (cores <= 0) return 1;
		cores_ = cores;
		return 0;
	}
	int SmartPhone::SetRAM(float ram)
	{
		if (ram <= 0) return 1;
		RAM_ = ram;
		return 0;
	}
	int SmartPhone::SetRAMtype(RAM ram_type)
	{
		if (ram_type > 1) return 1;
		RAM_type_ = ram_type;
		return 0;
	}
	int SmartPhone::SetROM(float rom)
	{
		if (rom <= 0) return 1;
		ROM_ = rom;
		return 0;
	}
	int SmartPhone::SetOSver(string os_ver)
	{
		if (os_ver == "") return 1;
		OS_ver_ = os_ver;
		return 0;
	}
	int SmartPhone::SetApps(map<string, float> apps)
	{
		for (auto item : apps)
		{
			if (item.first == "" || item.second <= 0) return 1;
		}
		apps_ = apps;
		return 0;
	}
	int SmartPhone::SetIMEI(string imei)
	{
		if (imei == "") return 1;
		if (imei.length() != 15) return 1;
		IMEI_.TAC = stoi(imei.substr(0, IMEI_.lenTAC));
		IMEI_.SNR = stoi(imei.substr(IMEI_.lenTAC, IMEI_.lenSNR));
		IMEI_.FAC = stoi(imei.substr(IMEI_.lenSNR + IMEI_.lenTAC, IMEI_.lenFAC));
		IMEI_.SP = stoi(imei.substr(IMEI_.lenSNR + IMEI_.lenTAC + IMEI_.lenFAC, IMEI_.lenSP));
		return 0;
	}

	int SmartPhone::SetOS(OS os, string os_ver)
	{
		if (os > 3) return 1;
		if (SetOSver(os_ver)) return 1;
		OS_ = os;
		return 0;
	}

	SmartPhone::SmartPhone(string brand, string model,
		float cr, short cores,
		float ram, RAM ram_type,
		float rom, string imei,
		OS OS, string OS_ver,
		map<string,	float> apps)
	{
		if (SetBrand(brand)) throw std::invalid_argument("Wrong brand");
		if (SetModel(model)) throw std::invalid_argument("Wrong model");
		if (SetClockRate(cr)) throw std::invalid_argument("Wrong clock rate");
		if (SetCores(cores)) throw std::invalid_argument("Wrong cores");
		if (SetRAM(ram)) throw std::invalid_argument("Wrong RAM");
		if (SetRAMtype(ram_type)) throw std::invalid_argument("Wrong RAM type");
		if (SetROM(rom)) throw std::invalid_argument("Wrong ROM");
		if (SetIMEI(imei)) throw std::invalid_argument("Wrong IMEI");
		if (SetApps(apps)) throw std::invalid_argument("Wrong apps list");
		if (SetOS(OS, OS_ver)) throw std::invalid_argument("Wrong OS and/or its version");
	}
	SmartPhone::SmartPhone(string brand, string model,
		float cr, short cores,
		float ram, RAM ram_type,
		float rom, string imei,
		map<string, float> apps)
	{
		if (SetBrand(brand)) throw std::invalid_argument("Wrong brand");
		if (SetModel(model)) throw std::invalid_argument("Wrong model");
		if (SetClockRate(cr)) throw std::invalid_argument("Wrong clock rate");
		if (SetCores(cores)) throw std::invalid_argument("Wrong cores");
		if (SetRAM(ram)) throw std::invalid_argument("Wrong RAM");
		if (SetRAMtype(ram_type)) throw std::invalid_argument("Wrong RAM type");
		if (SetROM(rom)) throw std::invalid_argument("Wrong ROM");
		if (SetIMEI(imei)) throw std::invalid_argument("Wrong IMEI");
		if (SetApps(apps)) throw std::invalid_argument("Wrong apps list");
		if (SetOS(None, "0")) throw std::invalid_argument("Wrong OS and/or its version");
	}

	float SmartPhone::GetUsedROM() const 
	{
		float sum = 0;
		for (auto item : apps_) sum += item.second;
		return sum;
	}

	int SmartPhone::AvApps()
	{
		if (apps_.empty()) throw std::invalid_argument("No app installed");
		return int((ROM_ - GetUsedROM()) / (GetUsedROM() / apps_.size()));
	}
	void SmartPhone::HardReset()
	{
		apps_ = map<string, float>{};
	}
	int SmartPhone::AddApp(string name, float size)
	{
		if (name == "") throw std::invalid_argument("Empty name");
		if (size <= 0) throw std::invalid_argument("Negative or zero size");
		apps_.emplace(name, size);
		return 0;
	}
	int SmartPhone::RemoveApp(string name)
	{
		try 
		{
			if (IsAppInstalled(name))
			{
				auto a = apps_.find(name);
				apps_.erase(a);
			}
			else throw std::invalid_argument("App is not installed");
		}
		catch(std::invalid_argument ex)
		{
			throw ex;
		}
		return 0;
	}
	int SmartPhone::IsAppInstalled(string name)
	{
		if (name == "") throw std::invalid_argument("Empty name");
		if (apps_.find(name) == apps_.end()) return 0;
		return 1;
	}

	std::ostream& operator<<(std::ostream& os, SmartPhone phone)
	{
		os << "SmartPhone:\n";
		os << "Brand: " << phone.GetBrand() << std::endl;
		os << "Model: " << phone.GetModel() << std::endl;
		os << "Clock rate: " << phone.GetClockRate() << std::endl;
		os << "Cores: " << phone.GetCores() << std::endl;
		os << "RAM: " << phone.GetRAM() << std::endl;
		os << "RAM type: " << phone.GetRAMtype() << std::endl;
		os << "ROM: " << phone.GetROM() << std::endl;
		os << "OS: " << phone.GetOS() << std::endl;
		os << "OS version: " << phone.GetOSver() << std::endl;
		os << "IMEI: " << phone.GetIMEI() << std::endl;
		os << "Apps: ";
		for (auto item : phone.GetApps()) os << item.first << ", " << item.second << "; ";
		os << std::endl;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, SmartPhone::IMEI imei)
	{
		os << imei.TAC << "-" << imei.SNR << "-" << imei.FAC << "-" << imei.SP;
		return os;
	}
}