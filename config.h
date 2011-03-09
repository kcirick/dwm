/*
 * DWM Configuration File
 */

// -- Appearance ----------------------------------------------------------------------------------
static const char font[]            = "-*-clean-medium-r-*-*-12-*-*-*-*-*-*-*";
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int systray_width      = 80;

#define NUMCOLORS			3	
static const char colors[NUMCOLORS][ColLast][8] = {
	// border	 foreground		background
	{ "#333333", "#FFFFFF", 	"#000000"},	// 0 - normal
	{ "#1793D0", "#1793D0", 	"#000000"}, // 1 - selected
	{ "#333333", "#333333",    "#000000"}, // 2 - inactive tags
};

// -- Tagging and Rules ---------------------------------------------------------------------------
static const char *tags[] = {"Eins", "Zwei", "Drei", "Vier", "Fünf", "Sechs", "Sieben"};

static const Rule rules[] = {
	/* class			  instance	  title			tags mask	isfloating	monitor */
	{ "Gimp",		  NULL,		  NULL,			0,				True,			-1 },
	{ "Chromium",	  NULL,		  NULL,	  		1 << 1,		False,		-1 },
	{ "Vlc",			  NULL,		  NULL,	  		0,				True,			-1 },
	{ "stalonetray", NULL,       NULL,    		~0,         True,    	-1 },
};

// -- Layout(s) -----------------------------------------------------------------------------------
static const float mfact      = 0.5;   /* factor of master area size [0.05..0.95] */
static const int nmaster 		= 1;  	/* default number of clients in the master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "T1",   ntile },
	{ "B1",   nbstack },
	{ "M0",   monocle },
	{ "FL",   NULL },    /* no layout function means floating behavior */
};

// -- key Definitions -----------------------------------------------------------------------------
#define MODKEY Mod4Mask		// Command Key
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,             KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask, KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask|ControlMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,							  XK_r,		 launcher,		  {0} },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = "urxvt" } },
	{ MODKEY|ShiftMask,				  XK_w,		 spawn,			  {.v = "chromium" } },
	{ MODKEY,                       XK_Down,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Up,     focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,							  XK_b,		 setlayout,		  {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,   setnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Right,  setnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,			     XK_Down,   pushdown,       {0} },
	{ MODKEY|ShiftMask,			     XK_Up,     pushup,         {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY,                       XK_w,      layer,          {0} },
	// Fn Hotkeys
	{ 0,  XF86XK_MonBrightnessDown,  spawn, {.v = "xbacklight -dec 15" } },          // F1
	{ 0,  XF86XK_MonBrightnessUp,    spawn, {.v = "xbacklight -inc 15" } },          // F2
	{ 0,  XF86XK_AudioPrev,          spawn, {.v = "ncmpcpp prev" } },                // F7
	{ 0,  XF86XK_AudioPlay,          spawn, {.v = "ncmpcpp toggle" } },              // F8
	{ 0,  XF86XK_AudioNext,          spawn, {.v = "ncmpcpp next" } },                // F9
	{ 0,  XF86XK_AudioMute,          spawn, {.v = "amixer -q set Master toggle" } }, // F10
	{ 0,  XF86XK_AudioLowerVolume,   spawn, {.v = "amixer -q set Master 5-" } },     // F11
	{ 0,  XF86XK_AudioRaiseVolume,   spawn, {.v = "amixer -q set Master 5+" } },     // F12
	{ 0,  XF86XK_Eject,              spawn, {.v = "eject /dev/sr0" } },              // Eject
};

// -- Button Definitions --------------------------------------------------------------------------
static Button buttons[] = {
	/* click         event mask        button    function        argument */
	{ ClkClientWin,  MODKEY,           Button1,  movemouse,      {0} },
	{ ClkClientWin,  MODKEY,           Button3,  togglefloating, {0} },
	{ ClkClientWin,  MODKEY|ShiftMask, Button1,  resizemouse,    {0} },
	{ ClkTagBar,     0,                Button1,  view,           {0} },
	{ ClkTagBar,     0,                Button3,  toggleview,     {0} },
	{ ClkTagBar,     MODKEY,           Button1,  tag,            {0} },
	{ ClkTagBar,     MODKEY,           Button3,  toggletag,      {0} },
};
