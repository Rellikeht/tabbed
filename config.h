/* See LICENSE file for copyright and license details. */

/* appearance */
#ifdef __linux__
static char font[256] = "MesloLGS:size=13:antialias=true:autohint=true";
#else
static char font[256] = "MesloLGS:size=13:antialias=true:autohint=true";
#endif

static char normbgcolor_buf[256] = "#01080b";
static char normfgcolor_buf[256] = "#086aab";
static char selbgcolor_buf[256] = "#18da4f";
static char selfgcolor_buf[256] = "#01080b";
static char urgbgcolor_buf[256] = "#e82442";
static char urgfgcolor_buf[256] = "#010b08";
static char before_buf[256] = "<";
static char after_buf[256] = ">";
static char titletrim_buf[256] = "...";

static char *normbgcolor = normbgcolor_buf;
static char *normfgcolor = normfgcolor_buf;
static char *selbgcolor = selbgcolor_buf;
static char *selfgcolor = selfgcolor_buf;
static char *urgbgcolor = urgbgcolor_buf;
static char *urgfgcolor = urgfgcolor_buf;
static char *before = before_buf;
static char *after = after_buf;
static char *titletrim = titletrim_buf;

static int tabwidth = 200;
static int focusnew = 1;
static int urgentswitch = 0;
// static int barHeight = 24;
#define barHeight dc.font.height+2;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int newposition = 1;
static int npisrelative = 1;

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

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
    {"font", STRING, font},
    {"normbgcolor", STRING, normbgcolor_buf},
    {"normfgcolor", STRING, normfgcolor_buf},
    {"selbgcolor", STRING, selbgcolor_buf},
    {"selfgcolor", STRING, selfgcolor_buf},
    {"urgbgcolor", STRING, urgbgcolor_buf},
    {"urgfgcolor", STRING, urgfgcolor_buf},
    {"before", STRING, before_buf},
    {"after", STRING, after_buf},
    {"titletrim", STRING, titletrim_buf},
    {"tabwidth", INTEGER, &tabwidth},
    {"focusnew", INTEGER, &focusnew},
    {"urgentswitch", INTEGER, &urgentswitch},
    {"newposition", INTEGER, &newposition},
    {"npisrelative", INTEGER, &npisrelative},
};

#define MODKEY Mod1Mask
#define CTRLMOD (MODKEY | ControlMask)
static const Key keys[] = {
    /* modifier             key        function     argument */
    // {CTRLMOD, XK_Return, focusonce, {0}},
    {CTRLMOD, XK_Return, spawn, {0}},
    {CTRLMOD, XK_o, focusonce, {0}},

    {CTRLMOD, XK_l, rotate, {.i = +1}},
    {CTRLMOD, XK_h, rotate, {.i = -1}},
    {CTRLMOD, XK_j, movetab, {.i = -1}},
    {CTRLMOD, XK_k, movetab, {.i = +1}},
    {CTRLMOD, XK_Tab, rotate, {.i = 0}},

    {CTRLMOD, XK_grave, spawn, SETPROP("_TABBED_SELECT_TAB")},
    {CTRLMOD, XK_1, move, {.i = 0}},
    {CTRLMOD, XK_2, move, {.i = 1}},
    {CTRLMOD, XK_3, move, {.i = 2}},
    {CTRLMOD, XK_4, move, {.i = 3}},
    {CTRLMOD, XK_5, move, {.i = 4}},
    {CTRLMOD, XK_6, move, {.i = 5}},
    {CTRLMOD, XK_7, move, {.i = 6}},
    {CTRLMOD, XK_8, move, {.i = 7}},
    {CTRLMOD, XK_9, move, {.i = 8}},
    {CTRLMOD, XK_0, move, {.i = 9}},

    {CTRLMOD, XK_c, killclient, {0}},

    {CTRLMOD, XK_u, focusurgent, {0}},
    {CTRLMOD | ShiftMask, XK_u, toggle, {.v = (void *)&urgentswitch}},

    {0, XK_F11, fullscreen, {0}},

    {MODKEY, XK_Control_L, showbar, {.i = 1}},
    {MODKEY, XK_Control_R, showbar, {.i = 1}},
    {ControlMask, XK_Alt_L, showbar, {.i = 1}},
    {ControlMask, XK_Alt_R, showbar, {.i = 1}},
};

static Key keyreleases[] = {
    /* modifier   key           function    argument */
    {CTRLMOD,     XK_Control_L, showbar,    {.i = 0}},
    {CTRLMOD,     XK_Control_R, showbar,    {.i = 0}},
    {CTRLMOD,     XK_Alt_L,     showbar,    {.i = 0}},
    {CTRLMOD,     XK_Alt_R,     showbar,    {.i = 0}},
};
