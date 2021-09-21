#include "../lv_examples.h"
#include "../get_started/user.c"
#include "../get_started/print.c"
#include "../get_started/menu.c"
#include "../get_started/cloud.c"
#include "../get_started/usb.c"
#include "../get_started/arrow.c"
#include "../get_started/empty.c"

#if LV_BUILD_EXAMPLES && LV_USE_BTN


extern const lv_img_dsc_t icon_names[] = {menu, user, cloud, print, usb};//empty
static const char * btnm_map[][34] = {{"_", " ", LV_SYMBOL_OK, LV_SYMBOL_CLOSE, LV_SYMBOL_BACKSPACE, LV_SYMBOL_KEYBOARD, LV_SYMBOL_EJECT, "1?&", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"},
                                      {"_", " ", LV_SYMBOL_OK, LV_SYMBOL_CLOSE, LV_SYMBOL_BACKSPACE, LV_SYMBOL_KEYBOARD, LV_SYMBOL_EJECT, "1?&", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"},
                                      {"¹", ",", LV_SYMBOL_OK, LV_SYMBOL_CLOSE, LV_SYMBOL_BACKSPACE, LV_SYMBOL_KEYBOARD, LV_SYMBOL_EJECT, "abc", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "!", "@", "#", "$", "%", "^", "&", "*", "-", "+", "?", "(", ")", "{", "}", "."},};


char  password[35] = {0};
char flag_keyboard_layout = 0;

lv_obj_t * pwd_ta;
lv_obj_t * main_screen;
lv_obj_t * screen;
lv_obj_t * screen_error;
static lv_style_t style;
lv_obj_t * parent;


LV_IMG_DECLARE(print);
LV_IMG_DECLARE(user);
LV_IMG_DECLARE(menu);
LV_IMG_DECLARE(cloud);
LV_IMG_DECLARE(usb);
LV_IMG_DECLARE(arrow);
LV_IMG_DECLARE(empty);


static void show_keyboard_layout(lv_obj_t * cont);


static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {

    }
}

static void btn_output_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
         lv_disp_load_scr (main_screen);
         lv_disp_get_scr_act(main_screen);
         lv_obj_del(screen);
         screen = NULL;
    }
}

static void imgbtn_print_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {

    }
}

static void imgbtn_usb_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {


    }
}

static void imgbtn_cloud_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {


    }
}

static void imgbtn_user_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        user_choice();
    }
}

static void imgbtn_menu_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {


    }
}

/**
 * Create a button with a label and react on click event.
 */
void lv_example_get_started_1(void)
{
    lv_example_scroll_6();
}

static void scroll_event_cb(lv_event_t * e)
{
    lv_obj_t * label = lv_event_get_user_data(e);
    lv_obj_t * cont = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_SCROLL ) {
        lv_area_t cont_a;
        lv_obj_get_coords(cont, &cont_a);
        lv_coord_t cont_x_center = cont_a.x1 + lv_area_get_width(&cont_a) / 2;

        lv_coord_t r = lv_obj_get_width(cont) * 7 / 10;
        uint32_t i;
        uint32_t child_cnt = lv_obj_get_child_cnt(cont);
        for(i = 0; i < child_cnt; i++) {
            lv_obj_t * child = lv_obj_get_child(cont, i);
            lv_area_t child_a;
            lv_obj_get_coords(child, &child_a);

            lv_coord_t child_x_center = child_a.x1 + lv_area_get_width(&child_a) / 2;

            lv_coord_t diff_x = child_x_center - cont_x_center;
            diff_x = LV_ABS(diff_x);

            lv_coord_t y;

            if(diff_x >= r) {
                y = r;
            } else {
                uint32_t x_sqr = r * r - diff_x * diff_x;
                lv_sqrt_res_t res;
                lv_sqrt(x_sqr, &res, 0x8000);
                y = r - res.i;

                uint32_t menu_count = (i != 0)? i-1: 0;
                switch(menu_count) {
                case 0:
                    lv_label_set_text(label, " ");
                    break;
                case 1:
                    lv_label_set_text(label, "Sign In");
                    break;
                case 2:
                    lv_label_set_text(label, "Cloud Apps");
                    break;
                case 3:
                    lv_label_set_text(label, "Print Stored jobs");
                    break;
                case 4:
                    lv_label_set_text(label, "USB");
                    break;
                default:
                    break;
                    }
            }

            /*Translate the item by the calculated X coordinate*/
            lv_obj_set_style_translate_y(child, y, 0);


            /*Use some opacity with larger translations*/
            lv_opa_t opa = lv_map(y, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
            lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
        }
    }
}

void lv_example_scroll_6(void)
{
    lv_style_init(&style);
    lv_style_set_radius(&style, 5);

    /*Make a gradient*/
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 1));

    main_screen = lv_obj_create(lv_scr_act());
    lv_obj_add_style(main_screen, &style, 0);
    lv_obj_set_size(main_screen, 300, 220);
    lv_obj_center(main_screen);
    lv_obj_set_flex_flow(main_screen, LV_FLEX_FLOW_ROW);

    lv_obj_t * info_label = lv_label_create(lv_scr_act());
    lv_label_set_text(info_label, " ");
    lv_obj_set_pos(info_label, 130, 200);

    lv_obj_add_event_cb(main_screen, scroll_event_cb, LV_EVENT_SCROLL, info_label);

    lv_obj_set_style_clip_corner(main_screen, true, 0);
    lv_obj_set_scroll_dir(main_screen, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(main_screen, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(main_screen, LV_SCROLLBAR_MODE_OFF);

    uint32_t i;
    uint32_t size_menu = sizeof(icon_names)/sizeof(icon_names[0]);

    for(i = 0; i < size_menu; i++) {
        show_menu_field(main_screen, i);
    }

    /*Update the buttons position manually for first*/
    lv_event_send(main_screen, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(main_screen, 2), LV_ANIM_OFF);
}

void show_menu_field(lv_obj_t * obj, uint32_t i)
{
    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, 110);
    lv_style_set_bg_opa(&style_btn, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, lv_palette_lighten(LV_PALETTE_GREY, 3));
    lv_style_set_bg_grad_color(&style_btn, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_bg_grad_dir(&style_btn, LV_GRAD_DIR_VER);

    lv_style_set_border_color(&style_btn, lv_color_black());
    lv_style_set_border_opa(&style_btn, LV_OPA_20);
    lv_style_set_border_width(&style_btn, 2);

    lv_style_set_text_color(&style_btn, lv_color_black());

    lv_obj_t * home_screen_buttons = lv_btn_create(obj);
    lv_obj_add_style(home_screen_buttons, &style_btn, 0);

    lv_obj_t * img = lv_img_create(home_screen_buttons);
    lv_img_set_src(img, &icon_names[i]);
    lv_obj_center(img);

    switch(i)
    {
        case 0: {lv_obj_add_event_cb(home_screen_buttons, imgbtn_menu_event_cb, LV_EVENT_ALL, NULL);   break;}
        case 1: {lv_obj_add_event_cb(home_screen_buttons, imgbtn_user_event_cb, LV_EVENT_ALL, NULL);   break;}
        case 2: {lv_obj_add_event_cb(home_screen_buttons, imgbtn_cloud_event_cb, LV_EVENT_ALL, NULL);   break;}
        case 3: {lv_obj_add_event_cb(home_screen_buttons, imgbtn_print_event_cb, LV_EVENT_ALL, NULL);   break;}
        case 4: {lv_obj_add_event_cb(home_screen_buttons, imgbtn_usb_event_cb, LV_EVENT_ALL, NULL);   break;}
        case 5: {break;}
        default: {break;}
    }

    lv_obj_set_width(home_screen_buttons, lv_pct(38));
}

static void btn_menu_password_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        menu_password_entry();
    }
}

void user_choice(void)
{
    password[0] = 0;
    //-------------------------------------------created a screen----------------------------------------------------
    screen = lv_obj_create(NULL);
    lv_scr_load(screen);
    lv_scr_act();//created a screen
    lv_obj_add_style(screen, &style, 0);
    //-------------------------------------------Style  Button----------------------------------------------------
    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, 30);
    lv_style_set_bg_opa(&style_btn, LV_OPA_COVER);
    lv_style_set_bg_color(&style_btn, lv_palette_lighten(LV_PALETTE_GREY, 3));
    lv_style_set_bg_grad_color(&style_btn, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_bg_grad_dir(&style_btn, LV_GRAD_DIR_VER);

    lv_style_set_border_color(&style_btn, lv_color_black());
    lv_style_set_border_opa(&style_btn, LV_OPA_20);
    lv_style_set_border_width(&style_btn, 2);

    lv_style_set_text_color(&style_btn, lv_color_black());

    //-------------------------------------------Button  exit----------------------------------------------------
    lv_obj_t * btn_exit = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn_exit, 125, 40);                            /*Set its position*/
    lv_obj_set_size(btn_exit, 70, 30);                          /*Set its size*/
    lv_obj_add_event_cb(btn_exit, btn_output_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/
    lv_obj_add_style(btn_exit, &style_btn, 0);

    lv_obj_t * obj = lv_img_create(btn_exit);
    lv_img_set_src(obj, &arrow);
    lv_obj_center(obj);


    //-------------------------------------------label  Sign In----------------------------------------------------
    lv_obj_t * label_text_user = lv_label_create(screen);          /*Add a label to the button*/
    lv_label_set_text(label_text_user, "Sign In");                     /*Set the labels text*/
    lv_obj_center(label_text_user);

    //-------------------------------------------Button  Admin----------------------------------------------------
    lv_obj_t * btn_admin = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn_admin, 125, 140);                            /*Set its position*/
    lv_obj_set_size(btn_admin, 70, 30);                          /*Set its size*/
    lv_obj_add_event_cb(btn_admin, btn_menu_password_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/
    lv_obj_add_style(btn_admin, &style_btn, 0);

    lv_obj_t * label_admin = lv_label_create(btn_admin);          /*Add a label to the button*/
    lv_label_set_text(label_admin, "Admin");                     /*Set the labels text*/
    lv_obj_center(label_admin);

    //-------------------------------------------Button  User----------------------------------------------------
    lv_obj_t * btn_user = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn_user, 125, 190);                            /*Set its position*/
    lv_obj_set_size(btn_user, 70, 30);                          /*Set its size*/
    lv_obj_add_event_cb(btn_user, btn_menu_password_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/
    lv_obj_add_style(btn_user, &style_btn, 0);

    lv_obj_t * label_user = lv_label_create(btn_user);          /*Add a label to the button*/
    lv_label_set_text(label_user, "User");                     /*Set the labels text*/
    lv_obj_center(label_user);
}

static void scroll_event_menu_password_cb(lv_event_t * e)
{
    lv_obj_t * pwd_text = lv_event_get_user_data(e);
    lv_obj_t * cont = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_SCROLL ) {

        lv_area_t cont_a;
        lv_obj_get_coords(cont, &cont_a);
        lv_coord_t cont_x_center = cont_a.x1 + lv_area_get_width(&cont_a) / 2;

        lv_coord_t r = lv_obj_get_width(cont) * 7 / 10;
        uint32_t i;
        uint32_t child_cnt = lv_obj_get_child_cnt(cont);
        for(i = 0; i < child_cnt; i++) {
            lv_obj_t * child = lv_obj_get_child(cont, i);
            lv_area_t child_a;
            lv_obj_get_coords(child, &child_a);

            lv_coord_t child_x_center = child_a.x1 + lv_area_get_width(&child_a) / 2;

            lv_coord_t diff_x = child_x_center - cont_x_center;
            diff_x = LV_ABS(diff_x);

            /*Get the y of diff_y on a circle.*/
            lv_coord_t y;
            /*If diff_x is out of the circle use the last point of the circle (the radius)*/
            if(diff_x >= r) {//child_x_center+diff_x >= r
                y = r;
            } else {
                /*Use Pythagoras theorem to get x from radius and y*/
                uint32_t x_sqr = r * r - diff_x * diff_x;
                lv_sqrt_res_t res;
                lv_sqrt(x_sqr, &res, 0x8000);   /*Use lvgl's built in sqrt root function*/
                y = r - res.i;

                switch(i) {
                case 2:
                    lv_label_set_text(pwd_text, "OK");
                    break;
                case 3:
                    lv_label_set_text(pwd_text, "Cancel");
                    break;
                case 4:
                    lv_label_set_text(pwd_text, "Delete");
                    break;
                case 5:
                    lv_label_set_text(pwd_text, "Language");
                    break;
                case 6:
                    lv_label_set_text(pwd_text, "Shift");
                    break;
                case 7:
                    lv_label_set_text(pwd_text, "Numbers");
                    break;
                default: {lv_label_set_text(pwd_text,btnm_map[flag_keyboard_layout][i]);
                    break;}

                    }
            }

            /*Translate the item by the calculated X coordinate*/
            lv_obj_set_style_translate_y(child, y, 0);

            /*Use some opacity with larger translations*/
            lv_opa_t opa = lv_map(y, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
            lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
        }
    }
}

static void textarea_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
        if(ta != NULL){
            lv_textarea_add_text(ta, lv_textarea_get_text(ta));
        }
    }
    else if(code == LV_EVENT_READY) {
        LV_LOG_USER("Ready, current text: %s", lv_textarea_get_text(ta));
    }
}

static void btn_enter_event_cb(lv_event_t * e)
{
    lv_obj_t * pwd = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {

    }
}

static void msgbox_close_click_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * mbox = lv_obj_get_parent(btn);

    if(code == LV_EVENT_VALUE_CHANGED) {
        uint32_t id = lv_btnmatrix_get_selected_btn(btn);

        if(id == 1)
        {
            user_choice();
        }

        lv_msgbox_close(parent);
    }
}

static void btn_cancel_event_cb(lv_event_t * e)
{
    lv_obj_t * pwd = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {
        strcpy(password, lv_textarea_get_text(pwd_ta));
        if(strlen(password) != 0)
        {
            static const char * btn_txts[] ={"Keep Editing", "\n", "Exit", ""};
            parent = lv_obj_create(lv_scr_act());
            lv_obj_remove_style_all(parent);
            lv_obj_set_style_bg_color(parent, lv_palette_main(LV_PALETTE_GREY), 0);
            lv_obj_set_style_bg_opa(parent, LV_OPA_50, 0);
            lv_obj_set_size(parent, LV_PCT(100), LV_PCT(100));

            lv_obj_t * mbox = lv_obj_class_create_obj(&lv_msgbox_class, parent);
            lv_obj_class_init_obj(mbox);
            LV_ASSERT_MALLOC(mbox);

            lv_obj_set_size(mbox, 200, LV_SIZE_CONTENT);
            lv_obj_set_flex_flow(mbox, LV_FLEX_FLOW_ROW_WRAP);
            lv_obj_set_flex_align(mbox, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);

            lv_obj_t * label;
            label = lv_label_create(mbox);
            lv_label_set_text(label, "Exit without saving?");

            lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
            label = lv_label_create(mbox);

            char text[] = "You entered '";
            strcat(text, password);
            strcat(text, "'");
            lv_label_set_text(label, text);

            lv_obj_t * btns = lv_btnmatrix_create(mbox);
            lv_btnmatrix_set_map(btns, btn_txts);
            lv_btnmatrix_set_btn_ctrl_all(btns, LV_BTNMATRIX_CTRL_CLICK_TRIG | LV_BTNMATRIX_CTRL_NO_REPEAT);


            uint32_t btn_cnt = 0;
            while(btn_txts[btn_cnt] && btn_txts[btn_cnt][0] != '\0') {
                btn_cnt++;
            }

            lv_obj_set_size(btns, 180, 60);
            lv_obj_add_flag(btns, LV_OBJ_FLAG_EVENT_BUBBLE);
            lv_obj_add_event_cb(btns, msgbox_close_click_event_cb, LV_EVENT_ALL, NULL);
            lv_obj_center(mbox);
        }
        else{
            user_choice();
        }
    }
}

static void btn_delete_event_cb(lv_event_t * e)
{
    lv_obj_t * pwd = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {
        lv_textarea_del_char(pwd_ta);           //delete simbol
    }
}

static void btn_language_event_cb(lv_event_t * e)
{
    lv_obj_t * pwd = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {

    }
}

static void btn_shift_event_cb(lv_event_t * e)
{
    lv_obj_t * pwd = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {
        flag_keyboard_layout = (flag_keyboard_layout == 0)? 1: 0;
        menu_password_entry();
    }
}

static void btn_numbers_event_cb(lv_event_t * e)
{
    lv_obj_t * cont = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {
        flag_keyboard_layout = (flag_keyboard_layout != 2)? 2: 0;
        menu_password_entry();
    }
}

static void btn_symbols_event_cb(lv_event_t * e)
{
    lv_obj_t * pwd = lv_event_get_user_data(e);

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED ) {
        lv_textarea_add_text(pwd_ta, lv_label_get_text(pwd));
    }
}

void menu_password_entry(void)
{
    screen = lv_obj_create(NULL);
    lv_scr_load(screen);
    lv_scr_act();

    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont, 300, 220);
    lv_obj_center(cont);
    lv_obj_add_style(cont, &style, 0);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);


    pwd_ta = lv_textarea_create(lv_scr_act());
    lv_textarea_set_password_mode(pwd_ta, true);
    lv_textarea_set_one_line(pwd_ta, true);
    lv_obj_set_size(pwd_ta, 110, 40);
    lv_obj_set_pos(pwd_ta, 100, 185);
    lv_obj_add_event_cb(cont, textarea_event_handler, LV_EVENT_READY, pwd_ta);
    lv_obj_add_state(pwd_ta, LV_STATE_FOCUSED);

    lv_obj_t * text_btn = lv_label_create(lv_scr_act());
    lv_label_set_text(text_btn, "R");
    lv_obj_set_pos(text_btn, 120, 140);

    lv_obj_t * password_text = lv_label_create(lv_scr_act());
    lv_label_set_text(password_text, "Password:");
    lv_obj_set_pos(password_text, 120, 160);

    lv_obj_set_style_clip_corner(cont, true, 0);
    lv_obj_set_scroll_dir(cont, LV_DIR_HOR);
    lv_obj_set_scroll_snap_x(cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_event_cb(cont, scroll_event_menu_password_cb, LV_EVENT_SCROLL, text_btn);

    show_keyboard_layout(cont);
    /*Update the buttons position manually for first*/
    lv_event_send(cont, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(cont, 2), LV_ANIM_OFF);
}

static void show_keyboard_layout(lv_obj_t * cont)
{
    uint32_t size_menu = sizeof(btnm_map[flag_keyboard_layout])/sizeof(btnm_map[flag_keyboard_layout][0]);

    for(uint32_t i = 0; i < size_menu; i++) {
        static lv_style_t style_btn;
        lv_style_init(&style_btn);
        lv_style_set_radius(&style_btn, 40);
        lv_style_set_bg_opa(&style_btn, LV_OPA_COVER);
        lv_style_set_bg_color(&style_btn, lv_palette_lighten(LV_PALETTE_GREY, 3));
        lv_style_set_bg_grad_color(&style_btn, lv_palette_main(LV_PALETTE_GREY));
        lv_style_set_bg_grad_dir(&style_btn, LV_GRAD_DIR_VER);

        lv_style_set_border_color(&style_btn, lv_color_black());
        lv_style_set_border_opa(&style_btn, LV_OPA_20);
        lv_style_set_border_width(&style_btn, 2);

        lv_style_set_text_color(&style_btn, lv_color_black());

        lv_obj_t *btns = lv_btn_create(cont);
        lv_obj_add_style(btns, &style_btn, 0);

        lv_obj_t * label = lv_label_create(btns);
        lv_label_set_text(label, btnm_map[flag_keyboard_layout][i]);

        switch(i)
        {
            case 2: {lv_obj_add_event_cb(btns, btn_enter_event_cb, LV_EVENT_ALL, NULL);   break;}
            case 3: {lv_obj_add_event_cb(btns, btn_cancel_event_cb, LV_EVENT_ALL, NULL);   break;}
            case 4: {lv_obj_add_event_cb(btns, btn_delete_event_cb, LV_EVENT_ALL, NULL);   break;}
            case 5: {lv_obj_add_event_cb(btns, btn_language_event_cb, LV_EVENT_ALL, NULL);   break;}
            case 6: {lv_obj_add_event_cb(btns, btn_shift_event_cb, LV_EVENT_ALL, NULL);   break;}
            case 7: {lv_obj_add_event_cb(btns, btn_numbers_event_cb, LV_EVENT_ALL, cont);   break;}
            default: {lv_obj_add_event_cb(btns, btn_symbols_event_cb, LV_EVENT_ALL, label);   break;}
        }

        lv_obj_center(label);
    }

}

#endif

