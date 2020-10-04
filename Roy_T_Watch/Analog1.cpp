// 
// 
// 

#include "Analog1.h"
static lv_obj_t* Second_Hand_s = nullptr;
static lv_obj_t* Minute_Hand_s = nullptr;
static lv_obj_t* Hour_Hand_s = nullptr;

static lv_obj_t* Hour_Hand = nullptr;
static lv_obj_t* Minute_Hand = nullptr;
static lv_obj_t* Second_Hand = nullptr;

void SetupAnalog1(lv_obj_t *face)
{
	// Watchface
	Second_Hand_s = lv_img_create(face, NULL);
	Minute_Hand_s = lv_img_create(face, NULL);
	Hour_Hand_s = lv_img_create(face, NULL);

	Hour_Hand = lv_img_create(face, NULL);
	Minute_Hand = lv_img_create(face, NULL);
	Second_Hand = lv_img_create(face, NULL);

	// Dial   to do..maybe


	///HandShadow
	// HourHand 
	LV_IMG_DECLARE(HourHand_S);
	lv_img_set_src(Hour_Hand_s, &HourHand_S);
	lv_img_set_antialias(Hour_Hand_s, true);
	lv_img_set_pivot(Hour_Hand_s, 20, 8);
	lv_obj_align(Hour_Hand_s, face, LV_ALIGN_IN_TOP_LEFT, 105, 130);
	lv_img_set_angle(Hour_Hand_s, 3300);
	// MinuteHand
	LV_IMG_DECLARE(MinuteHand_S);
	lv_img_set_src(Minute_Hand_s, &MinuteHand_S);
	lv_img_set_antialias(Minute_Hand_s, true);
	lv_img_set_pivot(Minute_Hand_s, 20, 8);
	lv_img_set_antialias(Minute_Hand_s, true);
	lv_obj_align(Minute_Hand_s, face, LV_ALIGN_IN_TOP_LEFT, 105, 130);
	lv_img_set_angle(Minute_Hand_s, 2100);
	// SecondHand
	LV_IMG_DECLARE(SecondHand_S);
	lv_img_set_src(Second_Hand_s, &SecondHand_S);
	lv_img_set_antialias(Second_Hand_s, true);
	lv_img_set_pivot(Second_Hand_s, 20, 8);
	lv_obj_align(Second_Hand_s, face, LV_ALIGN_IN_TOP_LEFT, 105, 130);
	lv_img_set_angle(Second_Hand_s, 900);

	// Normal Hand

	// HourHand
	LV_IMG_DECLARE(HourHand);
	lv_img_set_src(Hour_Hand, &HourHand);
	lv_img_set_antialias(Hour_Hand, true);
	lv_img_set_pivot(Hour_Hand, 20, 8);
	lv_obj_align(Hour_Hand, face, LV_ALIGN_IN_TOP_LEFT, 100, 120);
	lv_img_set_angle(Hour_Hand, 3300);
	// MinuteHand
	LV_IMG_DECLARE(MinuteHand);
	lv_img_set_src(Minute_Hand, &MinuteHand);
	lv_img_set_antialias(Minute_Hand, true);
	lv_img_set_pivot(Minute_Hand, 20, 8);
	lv_img_set_antialias(Minute_Hand, true);
	lv_obj_align(Minute_Hand, face, LV_ALIGN_IN_TOP_LEFT, 100, 120);
	lv_img_set_angle(Minute_Hand, 2100);
	// SecondHand
	LV_IMG_DECLARE(SecondHand);
	lv_img_set_src(Second_Hand, &SecondHand);
	lv_img_set_antialias(Second_Hand, true);
	lv_img_set_pivot(Second_Hand, 20, 8);
	lv_obj_align(Second_Hand, face, LV_ALIGN_IN_TOP_LEFT, 100, 120);
	lv_img_set_angle(Second_Hand, 900);

	// Shadow Style
	static lv_style_t hand_s_style;
	lv_style_set_image_opa(&hand_s_style, LV_STATE_DEFAULT, LV_OPA_20);
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
	int Angle_S, Angle_M, Angle_H;
	Angle_S = ((int)datetime.second * 60) + 2700;
	Angle_M = ((int)datetime.minute * 60) + 2700;
	Angle_H = ((int)datetime.hour * 300) + ((int)datetime.minute * 5) + 2700;

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