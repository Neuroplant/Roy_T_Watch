// Roy_T_Watch
// Analog Watchface 1 (analog1.cpp)
// 05.10.2020 Neuroplant

#include "Analog1.h"
#include "config.h"

void SetupAnalog1(lv_obj_t *face)
{
	//Background
	LV_IMG_DECLARE(BACKGROUND_PIC2);
	lv_img_set_src(face, &BACKGROUND_PIC2);
	lv_obj_align(face, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_style_set_bg_color(&bg_style2, LV_STATE_DEFAULT, LV_COLOR_LCD_BG_BL_ON);
	lv_style_set_bg_opa(&bg_style2, LV_STATE_DEFAULT, LV_OPA_50);
	lv_obj_add_style(face, LV_STATE_DEFAULT, &bg_style2);

	// Watchface
	Second_Hand_s = lv_img_create(face, NULL);
	Minute_Hand_s = lv_img_create(face, NULL);
	Hour_Hand_s = lv_img_create(face, NULL);

	Hour_Hand = lv_img_create(face, NULL);
	Minute_Hand = lv_img_create(face, NULL);
	Second_Hand = lv_img_create(face, NULL);

	// Dial   to do..maybe


	///HandShadow

	//Shadow offset y
	// HourHand 
	LV_IMG_DECLARE(HourHand_S);					// Select image for hand "HourHand_S.c"
	lv_img_set_src(Hour_Hand_s, &HourHand_S);
	lv_img_set_antialias(Hour_Hand_s, true);
	lv_img_set_pivot(Hour_Hand_s, 20, 8);
	lv_obj_align(Hour_Hand_s, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(Hour_Hand_s, 3300);
	// MinuteHand
	LV_IMG_DECLARE(MinuteHand_S);					// Select image for hand "MinuteHand_S.c"
	lv_img_set_src(Minute_Hand_s, &MinuteHand_S);
	lv_img_set_antialias(Minute_Hand_s, true);
	lv_img_set_pivot(Minute_Hand_s, 20, 8);
	lv_img_set_antialias(Minute_Hand_s, true);
	lv_obj_align(Minute_Hand_s, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(Minute_Hand_s, 2100);
	// SecondHand
	LV_IMG_DECLARE(SecondHand_S);					// Select image for hand "SecondHand_S.c"
	lv_img_set_src(Second_Hand_s, &SecondHand_S);
	lv_img_set_antialias(Second_Hand_s, true);
	lv_img_set_pivot(Second_Hand_s, 20, 8);
	lv_obj_align(Second_Hand_s, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20 +shadow_offsetx, (LV_VER_RES/2)-8 +shadow_offsety);
	lv_img_set_angle(Second_Hand_s, 900);

	// "Real" Hand
	// HourHand
	LV_IMG_DECLARE(HourHand);					// Select image for hand "HourHand.c"
	lv_img_set_src(Hour_Hand, &HourHand);
	lv_img_set_antialias(Hour_Hand, true);
	lv_img_set_pivot(Hour_Hand, 20, 8);
	lv_obj_align(Hour_Hand, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(Hour_Hand, 3300);
	// MinuteHand
	LV_IMG_DECLARE(MinuteHand);					// Select image for hand "MinuteHand.c"
	lv_img_set_src(Minute_Hand, &MinuteHand);
	lv_img_set_antialias(Minute_Hand, true);
	lv_img_set_pivot(Minute_Hand, 20, 8);
	lv_img_set_antialias(Minute_Hand, true);
	lv_obj_align(Minute_Hand, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(Minute_Hand, 2100);
	// SecondHand
	LV_IMG_DECLARE(SecondHand);					// Select image for hand "SecondHand.c"
	lv_img_set_src(Second_Hand, &SecondHand);
	lv_img_set_antialias(Second_Hand, true);
	lv_img_set_pivot(Second_Hand, 20, 8);
	lv_obj_align(Second_Hand, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)-20, (LV_VER_RES/2)-8);
	lv_img_set_angle(Second_Hand, 900);

	// Shadow Style
	static lv_style_t hand_s_style;
	lv_style_set_image_opa(&hand_s_style, LV_STATE_DEFAULT, LV_OPA_20);	//Style for Handshadows: Opaque 20%
	lv_obj_add_style(Second_Hand_s, LV_OBJ_PART_MAIN, &hand_s_style);
	lv_obj_add_style(Hour_Hand_s, LV_OBJ_PART_MAIN, &hand_s_style);
	lv_obj_add_style(Minute_Hand_s, LV_OBJ_PART_MAIN, &hand_s_style);

	// Normal Style
	static lv_style_t hand_style;
	lv_obj_add_style(Second_Hand, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(Hour_Hand, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(Minute_Hand, LV_OBJ_PART_MAIN, &hand_style);
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
	lv_img_set_angle(Second_Hand, Angle_S);
	lv_img_set_angle(Minute_Hand, Angle_M);
	lv_img_set_angle(Hour_Hand, Angle_H);

	//Shadow
	lv_img_set_angle(Second_Hand_s, Angle_S);
	lv_img_set_angle(Minute_Hand_s, Angle_M);
	lv_img_set_angle(Hour_Hand_s, Angle_H);
}
