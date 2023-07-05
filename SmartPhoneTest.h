#ifndef TEST
#define TEST
#include <string>
#include "SmartPhone.h"
#include <map>
namespace test
{
	static int passed_tests = 0;
	static int tests = 0;

	device::SmartPhone create_obj();
	int test_constructors();
	int test_getters();
	int test_methods();
	int test_friends();
	int all_tests();

	namespace constants
	{
		using std::string;
		using device::SmartPhone;
		using std::map;

		const string brand_corr = "Samsung";
		const string brand_incorr = "";

		const string model_corr = "A54";
		const string model_incorr = "";

		const float clock_rate_corr = 3.8f;
		const float clock_rate_incorr = -1;

		const short cores_corr = 8;
		const short cores_incorr = -1;

		const float RAM_corr = 8;
		const float RAM_incorr = -1;

		const SmartPhone::RAM RAM_type_corr = SmartPhone::RAM(0);
		const SmartPhone::RAM RAM_type_incorr = SmartPhone::RAM(3);

		const float ROM_corr = 256;
		const float ROM_incorr = -1;

		const SmartPhone::OS OS_corr = SmartPhone::OS(1);
		const SmartPhone::OS OS_incorr = SmartPhone::OS(4);
		const SmartPhone::OS OS_null = SmartPhone::None;

		const string OS_ver_corr = "13";
		const string OS_ver_incorr = "";
		const string OS_ver_null = "0";

		const map<string, float> apps_corr = map<string, float>{ {"Google", 0.472}, {"Telegram", 1.75}, {"Uber", 0.121} };
		const map<string, float> apps_incorr1 = map<string, float>{ {"Google", 0.472}, {"Telegram", -1}, {"Uber", 0.121} };
		const map<string, float> apps_incorr2 = map<string, float>{ {"Google", 0.472}, {"Telegram", 1.75}, {"", 0.121} };
		const map<string, float> apps_null = map<string, float>{};

		const string IMEI_corr = "447402515437650";
		const string IMEI_incorr1 = "";
		const string IMEI_incorr2 = "44740251543765";

		const float expexted_used_nvm = 2.343f;
		const int expected_avApps1 = 324;
		const map<string, float> expected_addApps1 = map<string, float>{ {"Google", 0.472}, {"Telegram", 1.75}, {"Uber", 0.121}, {"2GIS", 1.79} };
		const map<string, float> expected_removeApps1 = map<string, float>{ {"Telegram", 1.75}, {"Uber", 0.121} };
		const map<string, float> expected_removeApps2 = map<string, float>{ {"Google", 0.472}, {"Telegram", 1.75}, {"Uber", 0.121} };
	}
	namespace test_constructor
	{
		int test_const1_allright1();
		int test_const1_allright2();
		int test_const1_allright3();
		int test_const1_wrong_brand();
		int test_const1_wrong_model();
		int test_const1_wrong_clock_rate();
		int test_const1_wrong_cores();
		int test_const1_wrong_RAM();
		int test_const1_wrong_RAM_type();
		int test_const1_wrong_ROM();
		int test_const1_wrong_OS();
		int tets_const1_wrong_OS_ver();
		int test_const1_wrong_apps1();
		int test_const1_wrong_apps2();
		int test_conts1_wrong_IMEI1();
		int test_const1_wrong_IMEI2();
		int test_const2_allright();
	}
	namespace test_getter
	{
		int test_get_brand();
		int test_get_model();
		int test_get_clock_rate();
		int test_get_cores();
		int test_get_RAM();
		int test_get_RAM_type();
		int test_get_ROM();
		int test_get_OS();
		int test_get_OS_ver();
		int test_get_apps();
		int test_get_IMEI();
		int test_get_Used_NVM();
	}
	namespace test_method
	{
		int test_AvApps1();
		int test_AvApps2();
		int test_HardReset();
		int test_AddApp1();
		int test_AddApp2();
		int test_AddApp3();
		int test_RemoveApp1();
		int test_RemoveApp2();
		int test_RemoveApp3();
		int test_IsAppInstalled1();
		int test_IsAppInstalled2();
		int test_IsAppInstalled3();
	}
	namespace test_friend
	{
		int test_output_IMEI();
		int test_output_SmartPhone();
	}
}
#endif