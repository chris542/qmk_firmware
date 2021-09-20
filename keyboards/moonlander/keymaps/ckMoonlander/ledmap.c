#define WHITE { HSV_WHITE }
#define RED { HSV_RED }
#define CORAL { HSV_CORAL }
#define ORANGE { HSV_ORANGE }
#define GOLDENROD { HSV_GOLDENROD }
#define GOLD { HSV_GOLD }
#define YELLOW { HSV_YELLOW }
#define CHARTREUSE { HSV_CHARTREUSE }
#define GREEN { HSV_GREEN }
#define SPRINGGREEN { HSV_SPRINGGREEN }
#define TURQUOISE { HSV_TURQUOISE }
#define TEAL { HSV_TEAL }
#define CYAN { HSV_CYAN }
#define AZURE { HSV_AZURE }
#define BLUE { HSV_BLUE }
#define PURPLE { HSV_PURPLE }
#define MAGENTA { HSV_MAGENTA }
#define PINK { HSV_PINK }
#define NONE { HSV_OFF }

//MACBOOKLAYER = GREEN
//WINDOWSLAYER = BLUE
//GAME = YELLOW
//NUMPAD = TURQUOISE
//MOUSE = CHARTREUSE
//SYMB = ORANGE
//ARROW = WHITE
//FUNC = MAGENTA

PROGMEM uint8_t ledmap[][DRIVER_LED_TOTAL][3] = {
    //INDICATOR = GREEN
    //MAIN      = SPRINGGREEN
    //MODIFIERS = GREEN
    //SPECIALS  = CHARTREUSE
    //NUMBERS   = GOLDENROD
    //ARROWS    = GOLD
    [MacbookLayer] = {
        CHARTREUSE  , GREEN       , GREEN       , GREEN       , CHARTREUSE  ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , NONE        ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , CHARTREUSE  ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GREEN       ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GREEN       ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN ,
        GOLDENROD   , SPRINGGREEN , CHARTREUSE  ,
        SPRINGGREEN , GOLDENROD   , MAGENTA     ,
        YELLOW      ,

        GREEN       , SPRINGGREEN , GREEN       , GREEN       , GOLD        ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GOLD        ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GOLD        ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GOLD        ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN ,
        GOLDENROD   , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN ,
        GOLDENROD   , GREEN       , CHARTREUSE  ,
        CHARTREUSE  , WHITE       , MAGENTA     ,
        GREEN
    },

    //INDICATOR = BLUE
    //MAIN      = CYAN
    //MODIFIERS = BLUE
    //SPECIALS  = RED
    //NUMBERS   = GOLDENROD
    //ARROWS    = GOLD
    [WindowsLayer] = {
        RED       , BLUE      , BLUE    , BLUE , RED  ,
        GOLDENROD , CYAN      , CYAN    , CYAN , NONE ,
        GOLDENROD , CYAN      , CYAN    , CYAN , RED  ,
        GOLDENROD , CYAN      , CYAN    , CYAN , BLUE ,
        GOLDENROD , CYAN      , CYAN    , CYAN , BLUE ,
        GOLDENROD , CYAN      , CYAN    , CYAN ,
        GOLDENROD , CYAN      , RED     ,
        CYAN      , GOLDENROD , MAGENTA ,
        YELLOW    ,

        BLUE      , CYAN      , BLUE    , BLUE , GOLD ,
        GOLDENROD , CYAN      , CYAN    , CYAN , GOLD ,
        GOLDENROD , CYAN      , CYAN    , CYAN , GOLD ,
        GOLDENROD , CYAN      , CYAN    , CYAN , GOLD ,
        GOLDENROD , CYAN      , CYAN    , CYAN , CYAN ,
        GOLDENROD , CYAN      , CYAN    , CYAN ,
        GOLDENROD , BLUE      , RED     ,
        ORANGE    , WHITE     , MAGENTA ,
        BLUE
    },

    //INDICATOR = YELLOW
    //MAIN      = GOLD
    //MODIFIERS = ORANGE
    //SPECIALS  = RED
    //NUMBERS   = GOLDENROD
    //ARROWS    = GOLD
    [GameLayer] = {
        ORANGE    , NONE      , NONE    , ORANGE , ORANGE ,
        GOLDENROD , NONE      , GOLD    , NONE   , NONE   ,
        GOLDENROD , GOLD      , GOLD    , NONE   , NONE   ,
        GOLDENROD , NONE      , GOLD    , NONE   , RED    ,
        GOLDENROD , NONE      , NONE    , NONE   , ORANGE ,
        GOLDENROD , NONE      , NONE    , NONE   ,
        GOLDENROD , NONE      , RED     ,
        GOLD      , GOLDENROD , MAGENTA ,
        YELLOW    ,

        GOLDENROD , NONE      , NONE    , NONE   , NONE   ,
        GOLDENROD , NONE      , NONE    , NONE   , GOLD   ,
        GOLDENROD , NONE      , NONE    , GOLD   , GOLD   ,
        GOLDENROD , NONE      , NONE    , NONE   , GOLD   ,
        GOLDENROD , NONE      , NONE    , NONE   , NONE   ,
        GOLDENROD , NONE      , NONE    , NONE   ,
        GOLDENROD , NONE      , NONE    ,
        ORANGE    , WHITE     , MAGENTA ,
        AZURE
    },

    //INDICATOR = TURQUOISE
    //MAIN      = AZURE
    //MODIFIERS = NONE
    //SPECIALS  = WHITE/MAGENTA/ORANGE/RED/GREEN/GOLD
    //NUMBERS   = AZURE
    //ARROWS    = NONE
    [NumpadLayer] = {
        NONE          , NONE      , NONE    , NONE  , NONE  ,
        NONE          , NONE      , NONE    , NONE  , NONE  ,
        NONE          , NONE      , NONE    , NONE  , NONE  ,
        NONE          , NONE      , NONE    , NONE  , NONE  ,
        NONE          , NONE      , NONE    , NONE  , NONE  ,
        NONE          , NONE      , NONE    , NONE  ,
        NONE          , NONE      , NONE    ,
        GOLDENROD     , GOLDENROD , MAGENTA ,
        YELLOW          ,

        NONE          , NONE      , NONE    , NONE  , NONE  ,
        RED           , GREEN     , WHITE   , NONE  , NONE  ,
        ORANGE        , AZURE     , AZURE   , AZURE , NONE  ,
        MAGENTA       , AZURE     , AZURE   , AZURE , GOLD  ,
        WHITE         , AZURE     , AZURE   , AZURE , AZURE ,
        NONE          , NONE      , NONE    , NONE  ,
        NONE          , NONE      , NONE    ,
        TURQUOISE     , NONE      , MAGENTA ,
        NONE
    },

    //INDICATOR = CHARTREUSE
    //MAIN      = AZURE
    //MODIFIERS = NONE
    //SPECIALS  = WHITE/MAGENTA/ORANGE/RED/GREEN/GOLD
    //NUMBERS   = AZURE
    //ARROWS    = NONE
    [MouseLayer] = {
        NONE      , NONE       , CYAN    , CYAN  , NONE ,
        NONE      , NONE       , NONE    , NONE  , NONE ,
        NONE      , NONE       , NONE    , NONE  , NONE ,
        NONE      , NONE       , NONE    , NONE  , CYAN ,
        NONE      , NONE       , NONE    , NONE  , CYAN ,
        NONE      , NONE       , NONE    , NONE  ,
        NONE      , NONE       , NONE    ,
        GOLDENROD , GOLDENROD  , MAGENTA ,
        NONE      ,

        NONE      , NONE       , AZURE   , NONE  , NONE ,
        NONE      , NONE       , NONE    , NONE  , NONE ,
        NONE      , RED        , GOLD    , BLUE  , NONE ,
        NONE      , GOLD       , GOLD    , BLUE  , NONE ,
        NONE      , RED        , GOLD    , BLUE  , NONE ,
        NONE      , NONE       , RED     , RED   ,
        NONE      , NONE       , NONE    ,
        NONE      , CHARTREUSE , MAGENTA ,
        NONE
    },

    //INDICATOR = ORANGE
    //MAIN      = *
    //MODIFIERS = RED
    //SPECIALS  = PINK
    //NUMBERS   = NONE
    //ARROWS    = NONE
    [SymbolLayer] = {
        PINK   , RED    , RED       , RED    , PINK      ,
        NONE   , CYAN   , NONE      , NONE   , NONE      ,
        NONE   , CYAN   , TURQUOISE , NONE   , PINK      ,
        NONE   , CYAN   , TURQUOISE , NONE   , RED       ,
        NONE   , CYAN   , TURQUOISE , NONE   , RED       ,
        NONE   , CYAN   , NONE      , NONE   ,
        NONE   , CYAN   , NONE      ,
        NONE   , NONE   , MAGENTA   ,
        NONE   ,

        PINK   , NONE   , NONE      , NONE   , NONE      ,
        NONE   , NONE   , GOLDENROD , CYAN   , NONE      ,
        NONE   , CORAL  , CORAL     , CYAN   , NONE      ,
        NONE   , CORAL  , CORAL     , CYAN   , NONE      ,
        NONE   , ORANGE , GREEN     , GREEN  , TURQUOISE ,
        NONE   , CYAN   , ORANGE    , ORANGE ,
        PINK   , NONE   , PINK      ,
        ORANGE , NONE   , MAGENTA   ,
        NONE
    },

    //INDICATOR = WHITE
    //MAIN      = GOLD
    //MODIFIERS = CHARTREUSE
    //SPECIALS  = PINK
    //NUMBERS   = NONE
    //ARROWS    = GOLD
    [ArrowsLayer] = {
        PINK      , NONE      , CHARTREUSE , CHARTREUSE , PINK       ,
        NONE      , NONE      , NONE       , NONE       , NONE       ,
        NONE      , NONE      , NONE       , PINK       , PINK       ,
        NONE      , PINK      , NONE       , NONE       , CHARTREUSE ,
        NONE      , NONE      , NONE       , NONE       , CHARTREUSE ,
        NONE      , NONE      , NONE       , NONE       ,
        NONE      , NONE      , NONE       ,
        GOLDENROD , GOLDENROD , MAGENTA    ,
        NONE      ,

        NONE , NONE  , NONE    , NONE , NONE ,
        NONE , NONE  , NONE    , NONE , NONE ,
        NONE , NONE  , GOLD    , NONE , NONE ,
        NONE , PINK  , GOLD    , NONE , NONE ,
        NONE , NONE  , GOLD    , NONE , NONE ,
        NONE , NONE  , GOLD    , NONE ,
        NONE , NONE  , NONE    ,
        NONE , WHITE , MAGENTA ,
        NONE
    },

    //INDICATOR = MAGENTA
    [FuncLayer] = {
        NONE       , NONE       , NONE      , NONE      , WHITE  ,
        CHARTREUSE , RED        , NONE      , NONE      , NONE   ,
        CHARTREUSE , NONE       , CYAN      , YELLOW    , NONE   ,
        CHARTREUSE , NONE       , BLUE      , GREEN     , NONE   ,
        CHARTREUSE , NONE       , CYAN      , YELLOW    , NONE   ,
        CHARTREUSE , NONE       , GOLDENROD , GOLDENROD ,
        CHARTREUSE , NONE       , WHITE     ,
        NONE       , NONE       , MAGENTA   ,
        NONE       ,

        CHARTREUSE , CHARTREUSE , NONE      , NONE      , AZURE  ,
        CHARTREUSE , NONE       , NONE      , NONE      , NONE   ,
        CHARTREUSE , NONE       , GOLDENROD , GOLDENROD , NONE   ,
        CHARTREUSE , NONE       , NONE      , CYAN      , NONE   ,
        CHARTREUSE , NONE       , NONE      , CYAN      , PURPLE ,
        CHARTREUSE , NONE       , GOLDENROD , GOLDENROD ,
        CHARTREUSE , NONE       , RED       ,
        NONE       , NONE       , MAGENTA   ,
        NONE
    },
};

