#ifndef SMARTPHONE
#define SMARTPHONE
#include <string>
#include <map>
#include <ostream>
namespace device
{
	using std::string;
	using std::map;
	using std::ostream;
	using std::to_string;

	class SmartPhone
	{
	public:
		enum OS{None, Android, IOS, Windows};
		enum RAM{Dynamic, Static};
		struct IMEI
		{
			int TAC, SNR, FAC, SP;
			short lenTAC = 6, lenSNR = 6, lenFAC = 2, lenSP = 1;
			operator string() const { return to_string(TAC) + to_string(SNR) + to_string(FAC) + to_string(SP); }
		};
	private:
		string brand_;
		string model_;
		float clock_rate_;
		unsigned short cores_;
		float RAM_;
		RAM RAM_type_;
		float ROM_;
		OS OS_;
		string OS_ver_;
		map<string, float> apps_;
		IMEI IMEI_;

		int SetBrand(string brand);
		int SetModel(string model);
		int SetClockRate(float cr);
		int SetCores(short cores);
		int SetRAM(float ram);
		int SetRAMtype(RAM ram_type);
		int SetROM(float rom);
		int SetOSver(string os_ver);
		int SetApps(map<string, float>);
		int SetIMEI(string imei);
	public:
		SmartPhone(string brand, string model,
			float cr, short cores,
			float ram, RAM ram_type,
			float rom, string imei,
			OS OS_ = None, string OS_ver_ = "0",
			map<string,	float> apps = map<string, float>{});
		SmartPhone(string brand_, string model,
			float cr, short cores,
			float ram, RAM ram_type,
			float rom, string imei,
			map<string, float> apps);

		string GetBrand() const { return brand_; }
		string GetModel() const { return model_; }
		float GetClockRate() const { return clock_rate_; }
		unsigned short GetCores() const { return cores_; }
		float GetRAM() const { return RAM_; }
		RAM GetRAMtype() const { return RAM_type_; }
		float GetROM() const { return ROM_; }
		OS GetOS() const { return OS_; }
		string GetOSver() const { return OS_ver_; }
		map<string, float> GetApps() const { return apps_; }
		IMEI GetIMEI() const { return IMEI_; }
		float GetUsedROM() const;

		int SetOS(OS os, string os_ver);
		int AvApps();
		void HardReset();
		int AddApp(string name, float size);
		int RemoveApp(string name);
		int IsAppInstalled(string name);

		friend std::ostream& operator<<(std::ostream& os, SmartPhone phone);
		friend std::ostream& operator<<(std::ostream& os, IMEI imei);

	};
}
#endif
