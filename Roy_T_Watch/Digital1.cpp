// Roy_T_Watch
// Digital Watchface 1 (Digital1.cpp)
// 05.10.2020 Neuroplant

#include "Digital1.h"
#include "config.h"

void SetupDigital1(lv_obj_t *face)
{
    LV_FONT_DECLARE(D14Seg_32p);        //select font "D14Seg_32p.c" (for small fields)
    LV_FONT_DECLARE(D14Seg_64p);        //select font "D14Seg_64p.c" (for big fields)

    //Backround
    LV_IMG_DECLARE(BACKGROUND_PIC);
    lv_img_set_src(face, &BACKGROUND_PIC);
    lv_obj_align(face, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_style_set_bg_color(&bg_style, LV_STATE_DEFAULT, LV_COLOR_LCD_BG_BL_ON);
    lv_style_set_bg_opa(&bg_style, LV_STATE_DEFAULT, LV_OPA_50);
    lv_obj_add_style(face, LV_STATE_DEFAULT, &bg_style);
    
    //init styles
    lv_style_init(&style_D1);
    lv_style_init(&style_D1s);
    lv_style_init(&style_D2);
    lv_style_init(&style_D2s);
    
    //Set Text Color to black
    lv_style_set_text_color(&style_D1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D1s, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D2, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D2s, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    
    //Set Text fonts
    lv_style_set_text_font(&style_D1, LV_STATE_DEFAULT, &D14Seg_64p);
    lv_style_set_text_font(&style_D1s, LV_STATE_DEFAULT, &D14Seg_64p);
    lv_style_set_text_font(&style_D2, LV_STATE_DEFAULT, &D14Seg_32p);
    lv_style_set_text_font(&style_D2s, LV_STATE_DEFAULT, &D14Seg_32p);
    
    //Set Text Opaque (Cover for Text, 40% for Shadow)
    lv_style_set_text_opa(&style_D1, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_opa(&style_D1s, LV_STATE_DEFAULT, LV_OPA_40);
    lv_style_set_text_opa(&style_D2, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_opa(&style_D2s, LV_STATE_DEFAULT, LV_OPA_40);

    //init Textfields (Shadows)
    DDataS.hourmin = lv_label_create(face, nullptr);
    DDataS.date = lv_label_create(face, nullptr);
    DDataS.stat1 = lv_label_create(face, nullptr);
    DDataS.stat2 = lv_label_create(face, nullptr);
    DDataS.stat3 = lv_label_create(face, nullptr);
    DDataS.stat4 = lv_label_create(face, nullptr);

    //init Textfields (Shadows)
    DData.hourmin = lv_label_create(face, nullptr);
    DData.date = lv_label_create(face, nullptr);
    DData.stat1 = lv_label_create(face, nullptr);
    DData.stat2 = lv_label_create(face, nullptr);
    DData.stat3 = lv_label_create(face, nullptr);
    DData.stat4 = lv_label_create(face, nullptr);

    //assign styles
    lv_obj_add_style(DDataS.hourmin, LV_OBJ_PART_MAIN, &style_D1s);
    lv_obj_add_style(DDataS.date, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat1, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat2, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat3, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat4, LV_OBJ_PART_MAIN, &style_D2s);

    lv_obj_add_style(DData.hourmin, LV_OBJ_PART_MAIN, &style_D1);
    lv_obj_add_style(DData.date, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat1, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat2, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat3, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat4, LV_OBJ_PART_MAIN, &style_D2);

    //position fields
	
    
    lv_obj_align(DDataS.hourmin, face, LV_ALIGN_IN_TOP_LEFT, 5 + shadow_offsetx, 10 + shadow_offsety);
    lv_obj_align(DDataS.date, face, LV_ALIGN_IN_TOP_LEFT, 5 + shadow_offsetx, 76 + shadow_offsety);
    lv_obj_align(DDataS.stat1, face, LV_ALIGN_IN_TOP_LEFT, 10 + shadow_offsetx, 126 + shadow_offsety);
    lv_obj_align(DDataS.stat2, face, LV_ALIGN_IN_TOP_LEFT, (HOR_RES/2) + shadow_offsetx, 126 + shadow_offsety);
    lv_obj_align(DDataS.stat3, face, LV_ALIGN_IN_TOP_LEFT, 10 + shadow_offsetx, 163 + shadow_offsety);
    lv_obj_align(DDataS.stat4, face, LV_ALIGN_IN_TOP_LEFT, (HOR_RES/2) + shadow_offsetx, 163 + shadow_offsety);

    lv_obj_align(DData.hourmin, face, LV_ALIGN_IN_TOP_LEFT, 5, 10);
    lv_obj_align(DData.date, face, LV_ALIGN_IN_TOP_LEFT, 5, 76);
    lv_obj_align(DData.stat1, face, LV_ALIGN_IN_TOP_LEFT, 10, 126);
    lv_obj_align(DData.stat2, face, LV_ALIGN_IN_TOP_LEFT, (HOR_RES/2), 126);
    lv_obj_align(DData.stat3, face, LV_ALIGN_IN_TOP_LEFT, 10, 163);
    lv_obj_align(DData.stat4, face, LV_ALIGN_IN_TOP_LEFT, (HOR_RES/2), 163);
}

void UpdateDigital1(RTC_Date datetime, float Val1, int Val2, float Val3, int Val4)
{
    // ":" only on even seconds
    if (((datetime.second / 2) * 2) == (datetime.second))
    {
        lv_label_set_text_fmt(DDataS.hourmin, "%02u:%02u", datetime.hour, datetime.minute);
    } else {
        lv_label_set_text_fmt(DDataS.hourmin, "%02u %02u", datetime.hour, datetime.minute);
    };
    lv_label_set_text_fmt(DDataS.date, "%02u.%02u.%04u", datetime.day, datetime.month, datetime.year);
    lv_label_set_text_fmt(DDataS.stat1, "%0.02f A", Val1);
    lv_label_set_text_fmt(DDataS.stat2, "%02u", Val2);
    lv_label_set_text_fmt(DDataS.stat3, "%0.02f V", Val3);
    lv_label_set_text_fmt(DDataS.stat4, "%02u", Val4);

    lv_label_set_text(DData.hourmin, lv_label_get_text(DDataS.hourmin));
    lv_label_set_text(DData.date,lv_label_get_text(DDataS.date));
    lv_label_set_text(DData.stat1, lv_label_get_text(DDataS.stat1));
    lv_label_set_text(DData.stat2, lv_label_get_text(DDataS.stat2));
    lv_label_set_text(DData.stat3, lv_label_get_text(DDataS.stat3));
    lv_label_set_text(DData.stat4, lv_label_get_text(DDataS.stat4));
}
