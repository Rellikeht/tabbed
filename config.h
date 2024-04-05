/* See LICENSE file for copyright and license details. */

/* appearance */
// static const char font[]        = "monospace:size=9";
#ifdef __linux__
static const char font[] =
    "MesloLGS NF:pixelsize=13:antialias=true:autohint=true";
#else
static const char font[] = "MesloLGS:pixelsize=13:antialias=true:autohint=true";
#endif
// static const char* selbgcolor   = "#02c840";
// static const char* normbgcolor  = "#010b08";
// static const char* normfgcolor  = "#029f6f";
// static const char* selbgcolor   = "#08af4a";
// static const char* selfgcolor   = "#010b08";
static const char *urgbgcolor = "#d82452";
static const char *urgfgcolor = "#010b08";

static const char *normbgcolor = "#01080b";
static const char *normfgcolor = "#086aab";
static const char *selbgcolor = "#18ea4f";
static const char *selfgcolor = "#01080b";
// static const char* urgbgcolor   = "#380f08";
// static const char* urgfgcolor   = "#cc0000";
static const char before[] = "<";
static const char after[] = ">";
static const char titletrim[] = "...";
static const int tabwidth = 200;
static const Bool foreground = True;
static Bool urgentswitch = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int newposition = 0;
static Bool npisrelative = True;

#define SETPROP(p)                                                             \
  {                                                                            \
    .v = (char *[]) {                                                          \
      "/bin/sh", "-c",                                                         \
          "prop=\"`xwininfo -children -id $1 | grep '^     0x' |"              \
          "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |"       \
          "xargs -0 printf %b | dmenu -l 10 -w $1`\" &&"                       \
          "xprop -id $1 -f $0 8s -set $0 \"$prop\"",                           \
          p, winid, NULL                                                       \
    }                                                                          \
  }

#define MODKEY Mod1Mask
#define GOODMOD (MODKEY | ControlMask)
static Key keys[] = {
    /* modifier             key        function     argument */
    //	{ GOODMOD,		XK_Return, focusonce,   { 0 } },
    {GOODMOD, XK_Return, spawn, {0}},
    //	{ MODKEY,	        XK_Return, spawn,       { 0 } },
    {GOODMOD, XK_n, spawn, {0}},

    {GOODMOD, XK_l, rotate, {.i = +1}},
    {GOODMOD, XK_h, rotate, {.i = -1}},
    {GOODMOD, XK_j, movetab, {.i = -1}},
    {GOODMOD, XK_k, movetab, {.i = +1}},
    {GOODMOD, XK_Tab, rotate, {.i = 0}},

    {GOODMOD, XK_grave, spawn, SETPROP("_TABBED_SELECT_TAB")},
    {GOODMOD, XK_1, move, {.i = 0}},
    {GOODMOD, XK_2, move, {.i = 1}},
    {GOODMOD, XK_3, move, {.i = 2}},
    {GOODMOD, XK_4, move, {.i = 3}},
    {GOODMOD, XK_5, move, {.i = 4}},
    {GOODMOD, XK_6, move, {.i = 5}},
    {GOODMOD, XK_7, move, {.i = 6}},
    {GOODMOD, XK_8, move, {.i = 7}},
    {GOODMOD, XK_9, move, {.i = 8}},
    {GOODMOD, XK_0, move, {.i = 9}},

    //	{ MODKEY,               XK_c,      killclient,  { 0 } },
    {GOODMOD, XK_c, killclient, {0}},

    {GOODMOD, XK_u, focusurgent, {0}},
    {GOODMOD, XK_u, toggle, {.v = (void *)&urgentswitch}},

    {0, XK_F11, fullscreen, {0}},
    {MODKEY, XK_Control_L, showbar, {.i = 1}},
    {MODKEY, XK_Control_R, showbar, {.i = 1}},
    //	{ ShiftMask,            XK_Control_L, showbar,    { .i = 1 } },
    //	{ ShiftMask,            XK_Control_R, showbar,    { .i = 1 } },
};

static Key keyreleases[] = {
    /* modifier             key          function     argument */
    //	{ GOODMOD,     XK_Shift_L,  showbar,     { .i = 0 } },
    //	{ GOODMOD,     XK_Shift_R,  showbar,     { .i = 0 } },
    {GOODMOD, XK_Control_L, showbar, {.i = 0}},
    {GOODMOD, XK_Control_R, showbar, {.i = 0}},
};
