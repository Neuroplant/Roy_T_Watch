// Roy_T_Watch
// Analog Watchface 1 (Analog2.cpp)
// 11.10.2020 Neuroplant

#include "Analog2.h"
#include "config.h"

void SetupAnalog2(lv_obj_t* face)
{
	//Background
	LV_IMG_DECLARE(BACKGROUND_A2);
	lv_img_set_src(face, &BACKGROUND_A2);
	lv_obj_align(face, NULL, LV_ALIGN_CENTER, 0, 0);

	//Moon
	LV_IMG_DECLARE(Analog2_Moon);
	A2Data.Moon = lv_img_create(face, NULL);
	lv_img_set_src(A2Data.Moon, &Analog2_Moon);
	lv_obj_align(A2Data.Moon, face, LV_ALIGN_IN_TOP_LEFT, 45, 45);
	lv_img_set_pivot(A2Data.Moon, 75, 75);


	//Dial (with hole for Moon)
	LV_IMG_DECLARE(Analog2_Gauge);
	A2Data.Dial = lv_img_create(face, NULL);
	lv_img_set_src(A2Data.Dial, &Analog2_Gauge);
	lv_obj_align(A2Data.Dial, face, LV_ALIGN_IN_TOP_LEFT, 0, 0);

	//Gauge
	A2Data.Val1Gauge = lv_gauge_create(face, NULL);
	lv_gauge_set_scale(A2Data.Val1Gauge, 90, 5, 0);
	lv_gauge_set_angle_offset(A2Data.Val1Gauge, 0);
	lv_gauge_set_range(A2Data.Val1Gauge, 0, 100);
	lv_obj_set_size(A2Data.Val1Gauge, 60, 60);
	lv_gauge_set_critical_value(A2Data.Val1Gauge, 20); 
	lv_obj_align(A2Data.Val1Gauge, face, LV_ALIGN_IN_TOP_LEFT, 25, 135);
	lv_gauge_set_value(A2Data.Val1Gauge, 0, 50);

	// Watchface
	A2DataS.Second = lv_img_create(face, NULL);
	A2DataS.Minute = lv_img_create(face, NULL);
	A2DataS.Hour = lv_img_create(face, NULL);

	A2Data.Hour = lv_img_create(face, NULL);
	A2Data.Minute = lv_img_create(face, NULL);
	A2Data.Second = lv_img_create(face, NULL);

	///HandShadow

	//Shadow offset y
	// HourHand 
	lv_img_set_src(A2DataS.Hour, &HourHand_S);
	lv_img_set_antialias(A2DataS.Hour, true);
	lv_img_set_pivot(A2DataS.Hour, 20, 8);
	lv_obj_align(A2DataS.Hour, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(A2DataS.Hour, 3300);
	// MinuteHand
	lv_img_set_src(A2DataS.Minute, &MinuteHand_S);
	lv_img_set_antialias(A2DataS.Minute, true);
	lv_img_set_pivot(A2DataS.Minute, 20, 8);
	lv_img_set_antialias(A2DataS.Minute, true);
	lv_obj_align(A2DataS.Minute, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(A2DataS.Minute, 2100);
	// SecondHand
	lv_img_set_src(A2DataS.Second, &SecondHand_S);
	lv_img_set_antialias(A2DataS.Second, true);
	lv_img_set_pivot(A2DataS.Second, 20, 8);
	lv_obj_align(A2DataS.Second, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(A2DataS.Second, 900);

	// "Real" Hand
	// HourHand
	lv_img_set_src(A2Data.Hour, &HourHand);
	lv_img_set_antialias(A2Data.Hour, true);
	lv_img_set_pivot(A2Data.Hour, 20, 8);
	lv_obj_align(A2Data.Hour, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(A2Data.Hour, 3300);
	// MinuteHand
	lv_img_set_src(A2Data.Minute, &MinuteHand);
	lv_img_set_antialias(A2Data.Minute, true);
	lv_img_set_pivot(A2Data.Minute, 20, 8);
	lv_img_set_antialias(A2Data.Minute, true);
	lv_obj_align(A2Data.Minute, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(A2Data.Minute, 2100);
	// SecondHand
	lv_img_set_src(A2Data.Second, &SecondHand);
	lv_img_set_antialias(A2Data.Second, true);
	lv_img_set_pivot(A2Data.Second, 20, 8);
	lv_obj_align(A2Data.Second, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(A2Data.Second, 900);

	// Shadow Style
	static lv_style_t hand_s_style;
	lv_style_set_image_opa(&hand_s_style, LV_STATE_DEFAULT, LV_OPA_20);	//Style for Handshadows: Opaque 20%
	lv_obj_add_style(A2DataS.Second, LV_OBJ_PART_MAIN, &hand_s_style);
	lv_obj_add_style(A2DataS.Hour, LV_OBJ_PART_MAIN, &hand_s_style);
	lv_obj_add_style(A2DataS.Minute, LV_OBJ_PART_MAIN, &hand_s_style);

	// Normal Style
	static lv_style_t hand_style;
	lv_obj_add_style(A2Data.Second, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(A2Data.Hour, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(A2Data.Minute, LV_OBJ_PART_MAIN, &hand_style);
}
void UpdateAnalog2(RTC_Date datetime,int GaugeVal1)
{	
	//Angle calculation for Hands
	int Angle_S = ((int)datetime.second * 60) + 2700;			
	int Angle_M = ((int)datetime.minute * 60) + 2700;
	int Angle_H = ((int)datetime.hour * 300) + ((int)datetime.minute * 5) + 2700;

	int Angle_Moon = (8 * 1200 /(moon_phase(datetime)) );

	while (Angle_Moon >= 3600) Angle_Moon = Angle_Moon - 3600;
	while (Angle_S >= 3600) Angle_S = Angle_S - 3600;
	while (Angle_M >= 3600) Angle_M = Angle_M - 3600;
	while (Angle_H >= 3600) Angle_H = Angle_H - 3600;

	//Normal
	lv_img_set_angle(A2Data.Second, Angle_S);
	lv_img_set_angle(A2Data.Minute, Angle_M);
	lv_img_set_angle(A2Data.Hour, Angle_H);

	//Shadow
	lv_img_set_angle(A2DataS.Second, Angle_S);
	lv_img_set_angle(A2DataS.Minute, Angle_M);
	lv_img_set_angle(A2DataS.Hour, Angle_H);

	//Moon
	lv_img_set_angle(A2Data.Moon, Angle_Moon);

	//Gauge
	lv_gauge_set_value(A2Data.Val1Gauge, 1, 100-GaugeVal1);

}
