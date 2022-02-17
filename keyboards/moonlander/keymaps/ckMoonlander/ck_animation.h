RGB_MATRIX_EFFECT(layer_breathing)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "layers.c"
extern PROGMEM uint8_t ledmap[][DRIVER_LED_TOTAL][3];

static HSV FILTER_BREATH(HSV hsv, bool isBreathing){
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);

    if(isBreathing){
        hsv.v = scale8(abs8(sin8(time) - 128) * 2, rgb_matrix_config.hsv.v);
    }
    return hsv;
}

static HSV FILTER_HUE_BAND(HSV hsv, uint8_t position, bool isHueBanding, bool isVertical){
    if(isHueBanding){
        //hsv.h = scale8(h < 0 ? MOVINGHUE : CONSTANTHUE, hsv.h);
        if(isVertical){
            uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 12);
            int16_t h = hsv.h - abs(scale8(g_led_config.point[position].y, 228) + 28 - time) * 8;
            hsv.h = scale8(h < 0 ? hsv.h + 180 : hsv.h, hsv.h);
        } else {
            uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
            int16_t h = hsv.h - abs(scale8(g_led_config.point[position].x, 228) + 28 - time) * 8;
            hsv.h = scale8(h < 0 ? hsv.h + 180 : hsv.h, hsv.h);
        }
    }
    return hsv;
}

static HSV FILTER_SPREAD(HSV hsv, uint8_t position, bool isSpiral){
    if(isSpiral){
        uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 5);
        int16_t dx   = g_led_config.point[position].x - k_rgb_matrix_center.x;
        int16_t dy   = g_led_config.point[position].y - k_rgb_matrix_center.y;
        uint8_t dist = sqrt16(dx * dx + dy * dy);
        hsv.v = scale8(hsv.v + dist - time - atan2_8(dy, dx), hsv.v);
    }
    return hsv;
}

static HSV FILTER_CROSS_SPLASH(HSV hsv, uint8_t position, bool isSplashing){
    uint8_t count = g_last_hit_tracker.count;
    if(isSplashing){
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[position].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[position].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
            uint16_t effect = tick + dist;
            dx              = dx < 0 ? dx * -1 : dx;
            dy              = dy < 0 ? dy * -1 : dy;
            dx              = dx * 16 > 255 ? 255 : dx * 16;
            dy              = dy * 16 > 255 ? 255 : dy * 16;
            effect += dx > dy ? dy : dx;
            if (effect > 255) effect = 255;
            hsv.v = qadd8(hsv.v, 255 - effect);
        }
    }
    return hsv;
}

static HSV FILTER_SPLASH(HSV hsv, uint8_t position, bool isSplashing){
    uint8_t count = g_last_hit_tracker.count;
    if(isSplashing){
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[position].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[position].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
            uint16_t effect = tick + dist * 8;
            if (effect > 255) effect = 255;
            hsv.v = qadd8(hsv.v, 255 - effect);
        }
    }
    return hsv;
}

bool layer_breathing(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    int currentLayer = get_highest_layer(layer_state);
    for(uint8_t m = 0; m < DRIVER_LED_TOTAL; m++){
        HSV hsv = {
            .h   = pgm_read_byte(&ledmap[currentLayer][m][0]),
            .s   = pgm_read_byte(&ledmap[currentLayer][m][1]),
            .v   = pgm_read_byte(&ledmap[currentLayer][m][2]),
        };
        bool isVertical = true;
        bool isTurnedOff = !hsv.h && !hsv.s && !hsv.v;
        bool isAzure = hsv.h == 132 && hsv.s == 102 && hsv.v == 255;
        //bool isBlue = hsv.h == 170 && hsv.s == 255 && hsv.v == 255;
        bool isChartReuse = hsv.h == 64 && hsv.s == 255 && hsv.v == 255;
        //bool isCoral= hsv.h== 11 && hsv.s == 176 && hsv.v == 255;
        bool isCyan = hsv.h == 128 && hsv.s == 255 && hsv.v == 255;
        bool isGold = hsv.h == 36 && hsv.s == 255 && hsv.v == 255;
        //bool isGoldenRod = hsv.h == 30 && hsv.s == 218 && hsv.v == 218;
        //bool isGreen = hsv.h == 85 && hsv.s == 255 && hsv.v == 255;
        bool isMagenta = hsv.h == 213 && hsv.s == 255 && hsv.v == 255;
        //bool isOrange= hsv.h== 28 && hsv.s == 255 && hsv.v == 255;
        bool isRed= hsv.h== 0 && hsv.s == 255 && hsv.v == 255;
        bool isSpringGreen = hsv.h == 106 && hsv.s == 255 && hsv.v == 255;
        bool isPink = hsv.h == 234 && hsv.s == 128 && hsv.v == 255;
        bool isPurple = hsv.h == 191 && hsv.s == 255 && hsv.v == 255;
        bool isWhite = hsv.h == 0 && hsv.s == 0 && hsv.v == 255;

        //Sets the default value to the system value
        if(hsv.v) hsv.v = rgb_matrix_config.hsv.v;
        //BREATH/VAL_BAND THEN USE REACTIVE
        if(hsv.v){
            switch(currentLayer){
                case MacbookLayer:
                    hsv = FILTER_BREATH(hsv, isChartReuse);
                    hsv = FILTER_SPREAD(hsv, m, isSpringGreen);
                    hsv = FILTER_CROSS_SPLASH(hsv, m, !isTurnedOff && !isSpringGreen);
                    hsv = FILTER_SPLASH(hsv, m, isSpringGreen);
                    break;
                case WindowsLayer:
                    hsv = FILTER_BREATH(hsv, isRed);
                    hsv = FILTER_SPREAD(hsv, m, isCyan);
                    hsv = FILTER_CROSS_SPLASH(hsv, m, !isTurnedOff && !isCyan);
                    hsv = FILTER_SPLASH(hsv, m, isCyan);
                    break;
                case GameLayer:
                    hsv = FILTER_BREATH(hsv, isGold || m == 0);
                    hsv = FILTER_CROSS_SPLASH(hsv, m, isGold);
                    break;
                case NumpadLayer:
                    hsv = FILTER_BREATH(hsv, isAzure);
                    break;
                //case MouseLayer:
                case ArrowsLayer:
                    hsv = FILTER_BREATH(hsv, isGold);
                    hsv = FILTER_CROSS_SPLASH(hsv, m, isGold || isPink);
                    break;
                case SymbolLayer:
                    hsv = FILTER_BREATH(hsv, !isTurnedOff && !isPink && !isMagenta && !isRed);
                    hsv = FILTER_CROSS_SPLASH(hsv, m, !isTurnedOff);
                case FuncLayer:
                    hsv = FILTER_HUE_BAND(hsv, m, isChartReuse, !isVertical);
                    hsv = FILTER_BREATH(hsv, isRed || isWhite || isPurple);
                    break;
                default:
                    if(hsv.v) hsv.v = rgb_matrix_config.hsv.v;
                    break;
            }
        }
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        for (uint8_t i = led_min; i < led_max; i++) {
            RGB_MATRIX_TEST_LED_FLAGS();
            rgb_matrix_set_color(m, rgb.r, rgb.g, rgb.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
