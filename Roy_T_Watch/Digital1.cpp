// 
// 
// 

#include "Digital1.h"
#include "config.h"

void SetupDigital1(lv_obj_t *face)
{
    LV_FONT_DECLARE(D14Seg_32p);
    LV_FONT_DECLARE(D14Seg_64p);
    
    lv_style_init(&style_D1);
    lv_style_init(&style_D1s);
    lv_style_init(&style_D2);
    lv_style_init(&style_D2s);

    lv_style_set_text_color(&style_D1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D1s, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D2, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_text_color(&style_D2s, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_set_text_font(&style_D1, LV_STATE_DEFAULT, &D14Seg_64p);
    lv_style_set_text_font(&style_D1s, LV_STATE_DEFAULT, &D14Seg_64p);
    lv_style_set_text_font(&style_D2, LV_STATE_DEFAULT, &D14Seg_32p);
    lv_style_set_text_font(&style_D2s, LV_STATE_DEFAULT, &D14Seg_32p);

    lv_style_set_text_opa(&style_D1, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_opa(&style_D1s, LV_STATE_DEFAULT, LV_OPA_40);
    lv_style_set_text_opa(&style_D2, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_opa(&style_D2s, LV_STATE_DEFAULT, LV_OPA_40);

    DDataS.hourmin = lv_label_create(face, nullptr);
    //DDataS.second = lv_label_create(face, nullptr);
    DDataS.day = lv_label_create(face, nullptr);
    DDataS.month = lv_label_create(face, nullptr);
    DDataS.year = lv_label_create(face, nullptr);
    DDataS.stat1 = lv_label_create(face, nullptr);
    DDataS.stat2 = lv_label_create(face, nullptr);
    DDataS.stat3 = lv_label_create(face, nullptr);
    DDataS.stat4 = lv_label_create(face, nullptr);

    DData.hourmin = lv_label_create(face, nullptr);
    //DData.second = lv_label_create(face, nullptr);
    DData.day = lv_label_create(face, nullptr);
    DData.month = lv_label_create(face, nullptr);
    DData.year = lv_label_create(face, nullptr);
    DData.stat1 = lv_label_create(face, nullptr);
    DData.stat2 = lv_label_create(face, nullptr);
    DData.stat3 = lv_label_create(face, nullptr);
    DData.stat4 = lv_label_create(face, nullptr);

    lv_obj_add_style(DDataS.hourmin, LV_OBJ_PART_MAIN, &style_D1s);
    //  lv_obj_add_style(DDataS.second, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.day, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.month, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.year, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat1, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat2, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat3, LV_OBJ_PART_MAIN, &style_D2s);
    lv_obj_add_style(DDataS.stat4, LV_OBJ_PART_MAIN, &style_D2s);

    lv_obj_add_style(DData.hourmin, LV_OBJ_PART_MAIN, &style_D1);
    //   lv_obj_add_style(DData.second, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.day, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.month, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.year, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat1, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat2, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat3, LV_OBJ_PART_MAIN, &style_D2);
    lv_obj_add_style(DData.stat4, LV_OBJ_PART_MAIN, &style_D2);
    /*
    lv_label_set_text(DDataS.hourmin, "~~:~~");
    //lv_label_set_text(DDataS.second, "~~");
    lv_label_set_text(DDataS.day, "~~.");
    lv_label_set_text(DDataS.month, "~~.");
    lv_label_set_text(DDataS.year, "~~~~");
    lv_label_set_text(DDataS.stat1, "~.~~A");
    lv_label_set_text(DDataS.stat2, "~.~~V");
    lv_label_set_text(DDataS.stat3, "~.~~h");
    lv_label_set_text(DDataS.stat4, "~.~~s");

    lv_label_set_text(DData.hourmin, "~~:~~");
    //lv_label_set_text(DData.second, "~~");
    lv_label_set_text(DData.day, "~~.");
    lv_label_set_text(DData.month, "~~.");
    lv_label_set_text(DData.year, "~~~~");
    lv_label_set_text(DData.stat1, "~.~~A");
    lv_label_set_text(DData.stat2, "~.~~V");
    lv_label_set_text(DData.stat3, "~.~~h");
    lv_label_set_text(DData.stat4, "~.~~s");
    **/
    lv_obj_align(DDataS.hourmin, face, LV_ALIGN_IN_TOP_LEFT, 9, 14);
    // lv_obj_align(DDataS.second, face, LV_ALIGN_IN_TOP_LEFT, 204, 14);
    lv_obj_align(DDataS.day, face, LV_ALIGN_IN_TOP_LEFT, 9, 80);
    lv_obj_align(DDataS.month, face, LV_ALIGN_IN_TOP_LEFT, 54, 80);
    lv_obj_align(DDataS.year, face, LV_ALIGN_IN_TOP_LEFT, 104, 78);
    lv_obj_align(DDataS.stat1, face, LV_ALIGN_IN_TOP_LEFT, 14, 130);
    lv_obj_align(DDataS.stat2, face, LV_ALIGN_IN_TOP_LEFT, 114, 130);
    lv_obj_align(DDataS.stat3, face, LV_ALIGN_IN_TOP_LEFT, 14, 167);
    lv_obj_align(DDataS.stat4, face, LV_ALIGN_IN_TOP_LEFT, 114, 167);

    lv_obj_align(DData.hourmin, face, LV_ALIGN_IN_TOP_LEFT, 5, 10);
    // lv_obj_align(DData.second, face, LV_ALIGN_IN_TOP_LEFT, 200, 10);
    lv_obj_align(DData.day, face, LV_ALIGN_IN_TOP_LEFT, 5, 76);
    lv_obj_align(DData.month, face, LV_ALIGN_IN_TOP_LEFT, 50, 76);
    lv_obj_align(DData.year, face, LV_ALIGN_IN_TOP_LEFT, 100, 76);
    lv_obj_align(DData.stat1, face, LV_ALIGN_IN_TOP_LEFT, 10, 126);
    lv_obj_align(DData.stat2, face, LV_ALIGN_IN_TOP_LEFT, 110, 126);
    lv_obj_align(DData.stat3, face, LV_ALIGN_IN_TOP_LEFT, 10, 163);
    lv_obj_align(DData.stat4, face, LV_ALIGN_IN_TOP_LEFT, 110, 163);
}

void UpdateDigital1(RTC_Date datetime, float Val1, int Val2, float Val3, int Val4)
{
            if (((datetime.second / 2) * 2) == (datetime.second))//":" only on even seconds
            {
                lv_label_set_text_fmt(DDataS.hourmin, "%02u:%02u", datetime.hour, datetime.minute);
            }
            else {
                lv_label_set_text_fmt(DDataS.hourmin, "%02u %02u", datetime.hour, datetime.minute);
            };
            //  lv_label_set_text_fmt(DDataS.second, "%02u", datetime.second);
            lv_label_set_text_fmt(DDataS.day, "%02u.%02u.%04u", datetime.day, datetime.month, datetime.month);
            lv_label_set_text(DDataS.month, "");
            lv_label_set_text(DDataS.year, "");
            lv_label_set_text_fmt(DDataS.stat1, "%0.02f A", Val1);
            lv_label_set_text_fmt(DDataS.stat2, "%02u", Val2);
            lv_label_set_text_fmt(DDataS.stat3, "%0.02f V", Val3);
            lv_label_set_text_fmt(DDataS.stat4, "%02u", Val4);

            if (((datetime.second / 2) * 2) == (datetime.second)) //":" only on even seconds
            {
                lv_label_set_text_fmt(DData.hourmin, "%02u:%02u", datetime.hour, datetime.minute);
            }
            else {
                lv_label_set_text_fmt(DData.hourmin, "%02u %02u", datetime.hour, datetime.minute);
            };  //  lv_label_set_text_fmt(DData.second, "%02u", datetime.second);
            lv_label_set_text_fmt(DData.day, "%02u.%02u.%04u", datetime.day, datetime.month, datetime.year);
            lv_label_set_text(DData.month, "");
            lv_label_set_text(DData.year, "");
            lv_label_set_text_fmt(DData.stat1, "%.3f A", Val1);
            lv_label_set_text_fmt(DData.stat2, "%02u", Val2);
            lv_label_set_text_fmt(DData.stat3, "%.3f V", Val3);
            lv_label_set_text_fmt(DData.stat4, "%02u", Val4);
}
