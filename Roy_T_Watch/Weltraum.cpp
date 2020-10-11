// Roy_T_Watch
// Weltraum Watchface (Weltraum.cpp)
// 11.10.2020 Neuroplant

#include "Weltraum.h"
#include "config.h"

void SetupWeltraum(lv_obj_t *face)
{
	//Background
	LV_IMG_DECLARE(BACKGROUND_SPACE);
	lv_img_set_src(face, &BACKGROUND_SPACE);
	lv_obj_align(face, NULL, LV_ALIGN_CENTER, 0, 0);


	// Watchface

	SData.Hour = lv_img_create(face, NULL);
	SData.Minute = lv_img_create(face, NULL);
	SData.Second = lv_img_create(face, NULL);

	// Dial   to do..maybe


	// HourHand
	LV_IMG_DECLARE(erde);					// Select image for hand "HourHand.c"
	lv_img_set_src(SData.Hour, &erde);
	lv_img_set_antialias(SData.Hour, true);
	lv_img_set_pivot(SData.Hour, -39, 25);
	lv_obj_align(SData.Hour, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)+39, (LV_VER_RES/2)-25);
	lv_img_set_angle(SData.Hour, 3300);
	// MinuteHand
	LV_IMG_DECLARE(mond);					// Select image for hand "MinuteHand.c"
	lv_img_set_src(SData.Minute, &mond);
	lv_img_set_antialias(SData.Minute, true);
	lv_img_set_pivot(SData.Minute, -94, 10);
	lv_img_set_antialias(SData.Minute, true);
	lv_obj_align(SData.Minute, face, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)+94, (LV_VER_RES/2)-10);
	lv_img_set_angle(SData.Minute, 2100);
	// SecondHand
	LV_IMG_DECLARE(rakete);					// Select image for hand "SecondHand.c"
	lv_img_set_src(SData.Second, &rakete);
	lv_img_set_antialias(SData.Second, true);
	lv_img_set_pivot(SData.Second, -30, 8);
	lv_obj_align(SData.Second, SData.Minute, LV_ALIGN_IN_TOP_LEFT, (LV_HOR_RES/2)+33, (LV_VER_RES/2)-10);
	lv_img_set_angle(SData.Second, 900);

		// Normal Style
	static lv_style_t hand_style;
	lv_obj_add_style(SData.Second, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(SData.Hour, LV_OBJ_PART_MAIN, &hand_style);
	lv_obj_add_style(SData.Minute, LV_OBJ_PART_MAIN, &hand_style);
}
void UpdateWeltraum(RTC_Date datetime)
{	
	//Angle calculation for Hands
	int Angle_S = ((int)datetime.second * 60) + 2700;			
	int Angle_M = ((int)datetime.minute * 60) + 2700;
	int Angle_H = ((int)datetime.hour * 300) + ((int)datetime.minute * 5) + 2700;

	while (Angle_S >= 3600) Angle_S = Angle_S - 3600;
	while (Angle_M >= 3600) Angle_M = Angle_M - 3600;
	while (Angle_H >= 3600) Angle_H = Angle_H - 3600;

	//Normal
	lv_obj_align(SData.Second, SData.Hour, LV_ALIGN_CENTER, 0, 0);
	lv_img_set_angle(SData.Second, Angle_S);
	lv_img_set_angle(SData.Minute, Angle_M);
	lv_img_set_angle(SData.Hour, Angle_H);

}
