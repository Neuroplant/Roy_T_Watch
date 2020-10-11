// Roy_T_Watch
// Analog Watchface 1 (Analog1.cpp)
// 11.10.2020 Neuroplant

#include "Analog1.h"
#include "config.h"

void SetupAnalog1(lv_obj_t* face)
{
	//Background
	LV_IMG_DECLARE(BACKGROUND_A1);
	lv_img_set_src(face, &BACKGROUND_A1);
	lv_obj_align(face, NULL, LV_ALIGN_CENTER, 0, 0);

	// Watchface
	ADataS.Second = lv_img_create(face, NULL);
	ADataS.Minute = lv_img_create(face, NULL);
	ADataS.Hour = lv_img_create(face, NULL);

	AData.Hour = lv_img_create(face, NULL);
	AData.Minute = lv_img_create(face, NULL);
	AData.Second = lv_img_create(face, NULL);

	///HandShadow

	//Shadow offset y
	// HourHand 
	lv_img_set_src(ADataS.Hour, &HourHand_S);
	lv_img_set_antialias(ADataS.Hour, true);
	lv_img_set_pivot(ADataS.Hour, 20, 8);
	lv_obj_align(ADataS.Hour, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(ADataS.Hour, 3300);
	// MinuteHand
	lv_img_set_src(ADataS.Minute, &MinuteHand_S);
	lv_img_set_antialias(ADataS.Minute, true);
	lv_img_set_pivot(ADataS.Minute, 20, 8);
	lv_img_set_antialias(ADataS.Minute, true);
	lv_obj_align(ADataS.Minute, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(ADataS.Minute, 2100);
	// SecondHand
	lv_img_set_src(ADataS.Second, &SecondHand_S);
	lv_img_set_antialias(ADataS.Second, true);
	lv_img_set_pivot(ADataS.Second, 20, 8);
	lv_obj_align(ADataS.Second, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(ADataS.Second, 900);

	// "Real" Hand
	// HourHand
	lv_img_set_src(AData.Hour, &HourHand);
	lv_img_set_antialias(AData.Hour, true);
	lv_img_set_pivot(AData.Hour, 20, 8);
	lv_obj_align(AData.Hour, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(AData.Hour, 3300);
	// MinuteHand
	lv_img_set_src(AData.Minute, &MinuteHand);
	lv_img_set_antialias(AData.Minute, true);
	lv_img_set_pivot(AData.Minute, 20, 8);
	lv_img_set_antialias(AData.Minute, true);
	lv_obj_align(AData.Minute, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(AData.Minute, 2100);
	// SecondHand
	lv_img_set_src(AData.Second, &SecondHand);
	lv_img_set_antialias(AData.Second, true);
	lv_img_set_pivot(AData.Second, 20, 8);
	lv_obj_align(AData.Second, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(AData.Second, 900);

	// Shadow Style
	static lv_style_t hand_s_style;
	lv_style_set_image_opa(&hand_s_style, LV_STATE_DEFAULT, LV_OPA_20);	//Style for Handshadows: Opaque 20%
	lv_obj_add_style(ADataS.Second, LV_OBJ_PART_MAIN, &hand_s_style);
	lv_obj_add_style(ADataS.Hour, LV_OBJ_PART_MAIN, &hand_s_style);
	lv_obj_add_style(ADataS.Minute, LV_OBJ_PART_MAIN, &hand_s_style);

	// Normal Style
	static lv_style_t hand_style;
	lv_obj_add_style(AData.Second, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(AData.Hour, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(AData.Minute, LV_OBJ_PART_MAIN, &hand_style);
}
void UpdateAnalog1(RTC_Date datetime)
{	
	//Angle calculation for Hands
	int Angle_S = ((int)datetime.second * 60) + 2700;			
	int Angle_M = ((int)datetime.minute * 60) + 2700;
	int Angle_H = ((int)datetime.hour * 300) + ((int)datetime.minute * 5) + 2700;

	while (Angle_S >= 3600) Angle_S = Angle_S - 3600;
	while (Angle_M >= 3600) Angle_M = Angle_M - 3600;
	while (Angle_H >= 3600) Angle_H = Angle_H - 3600;

	//Normal
	lv_img_set_angle(AData.Second, Angle_S);
	lv_img_set_angle(AData.Minute, Angle_M);
	lv_img_set_angle(AData.Hour, Angle_H);

	//Shadow
	lv_img_set_angle(ADataS.Second, Angle_S);
	lv_img_set_angle(ADataS.Minute, Angle_M);
	lv_img_set_angle(ADataS.Hour, Angle_H);
}
