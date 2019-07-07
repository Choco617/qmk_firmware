#include "tap_dances.h"
#include "secrets.h"

#define PW secrets[2]

// for quad tap dance, see example 4 here:  https://docs.qmk.fm/feature_tap_dance.html#complex-examples

// taps 1-4 do (, [, {, and <
enum complex_tap_dance_L {
  SINGLE_TAP_L = 1,
  DOUBLE_TAP_L = 2,
  TRIPLE_TAP_L = 3,
  QUADRU_TAP_L = 4
};

// taps 1-4 do ), ], }, and >
enum complex_tap_dance_R {
  SINGLE_TAP_R = 1,
  DOUBLE_TAP_R = 2,
  TRIPLE_TAP_R = 3,
  QUADRU_TAP_R = 4
};

// taps 1 and 2 do "/" and "\"
enum complex_slash {
	SINGLE_SLS = 1,
	DOUBLE_SLS = 2
};

// taps 1 and 2 do - and =
enum dash_equal {
	SINGLE_DASH = 1,
	DOUBLE_DASH = 2
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance_L (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    /* if count = 1, simply return SINGLE_TAP_L */
    return SINGLE_TAP_L;
  }
  else if (state->count == 2) {
    /* likewise double */
    return DOUBLE_TAP_L;
  }
  else if (state->count == 3) {
    /* likewise triple */
    return TRIPLE_TAP_L;
  }
  /* likewise quad */
  else return QUADRU_TAP_L;
}

int cur_dance_R (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    /* if count = 1, simply return SINGLE_TAP_R */
    return SINGLE_TAP_R;
  }
  else if (state->count == 2) {
    /* likewise double */
    return DOUBLE_TAP_R;
  }
  else if (state->count == 3) {
    /* likewise triple */
    return TRIPLE_TAP_R;
  }
  /* likewise quad */
  else return QUADRU_TAP_R;
}

int cur_dance_sls (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		/* if count = 1, simply return SINGLE_SLS */
		return SINGLE_SLS;
	}
		/* else double */
	else return DOUBLE_SLS;
}

int cur_dance_dash (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		/* if count = 1, simply return SINGLE_DASH */
		return SINGLE_DASH;
	}
		/* else double */
	else return DOUBLE_DASH;
}

/* initialize an instance of 'tap' for the single-tap L */
static tap tapL_state = {
  .is_press_action = true,
  .state = 0
};

void finished_L (qk_tap_dance_state_t *state, void *user_data) {
  tapL_state.state = cur_dance_L(state);
  switch (tapL_state.state) {
    case SINGLE_TAP_L: register_code(KC_LSFT); register_code(KC_9); break;
    case DOUBLE_TAP_L: register_code(KC_LBRC); break;
    case TRIPLE_TAP_L: register_code(KC_LSFT); register_code(KC_LBRC); break;
    case QUADRU_TAP_L: register_code(KC_LSFT); register_code(KC_COMM);
  }
}

void reset_L (qk_tap_dance_state_t *state, void *user_data) {
  switch (tapL_state.state) {
    case SINGLE_TAP_L: unregister_code(KC_9); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP_L: unregister_code(KC_LBRC); break;
    case TRIPLE_TAP_L: unregister_code(KC_LBRC); unregister_code(KC_LSFT); break;
    case QUADRU_TAP_L: unregister_code(KC_COMM); unregister_code(KC_LSFT);
  }
  tapL_state.state = 0;
}

/* initialize an instance of 'tap' for the single-tap R */
static tap tapR_state = {
  .is_press_action = true,
  .state = 0
};

void finished_R (qk_tap_dance_state_t *state, void *user_data) {
  tapR_state.state = cur_dance_R(state);
  switch (tapR_state.state) {
    case SINGLE_TAP_R: register_code(KC_LSFT); register_code(KC_0); break;
    case DOUBLE_TAP_R: register_code(KC_RBRC); break;
    case TRIPLE_TAP_R: register_code(KC_LSFT); register_code(KC_RBRC); break;
    case QUADRU_TAP_R: register_code(KC_LSFT); register_code(KC_DOT);
  }
}

void reset_R (qk_tap_dance_state_t *state, void *user_data) {
  switch (tapR_state.state) {
    case SINGLE_TAP_R: unregister_code(KC_0); unregister_code(KC_LSFT); break;
    case DOUBLE_TAP_R: unregister_code(KC_RBRC); break;
    case TRIPLE_TAP_R: unregister_code(KC_RBRC); unregister_code(KC_LSFT); break;
    case QUADRU_TAP_R: unregister_code(KC_DOT); unregister_code(KC_LSFT);
  }
  tapR_state.state = 0;
}

/* initialize an instance of 'tap' for the single-tap slash */
static tap tapSlash_state = {
  .is_press_action = true,
  .state = 0
};

void finished_slash (qk_tap_dance_state_t *state, void *user_data) {
	tapSlash_state.state = cur_dance_sls(state);
	switch (tapSlash_state.state) {
		case SINGLE_SLS: register_code(KC_SLSH); break;
		case DOUBLE_SLS: register_code(KC_BSLS);
	}
}

void reset_slash (qk_tap_dance_state_t *state, void *user_data) {
	switch (tapSlash_state.state) {
		case SINGLE_SLS: unregister_code(KC_SLSH); break;
		case DOUBLE_SLS: unregister_code(KC_BSLS);
	}
}

/* initialize an instance of 'tap' for the single-tap dash */
static tap tapDash_state = {
  .is_press_action = true,
  .state = 0
};

void finished_dash (qk_tap_dance_state_t *state, void *user_data) {
	tapDash_state.state = cur_dance_dash(state);
	switch (tapDash_state.state) {
		case SINGLE_DASH: register_code(KC_MINUS); break;
		case DOUBLE_DASH: register_code(KC_EQL);
	}
};

void reset_dash (qk_tap_dance_state_t *state, void *user_data) {
	tapDash_state.state = cur_dance_dash(state);
	switch (tapDash_state.state) {
		case SINGLE_DASH: unregister_code(KC_MINUS); break;
		case DOUBLE_DASH: unregister_code(KC_EQL);
	}
}

void tap_dance_login (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:

      /* just enter password and enter */
      // for now PW will be in quotes because I can't get the define working, this needs to be fixed before I can use it
      SEND_STRING("PW" SS_TAP(X_ENTER));
      break;

    case 2:

      /* Ctrl-Alt-Del, password, and enter */

      /* tap Ctrl to wake */
      register_code(KC_LCTL);
      unregister_code(KC_LCTL);

      /* now wait just a darn minute */
      _delay_ms(250);
      
      /* Ctrl-Alt-Del */
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_DEL);
      unregister_code(KC_DEL);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);

      /* wait again */
      _delay_ms(250);

      /* login */
      SEND_STRING("PW" SS_TAP(X_ENTER));
      break;

  }
};

// tap dance definitions
// format copied from https://www.reddit.com/r/olkb/comments/4uqkp7/programming_help_tap_dance_please/
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_EXLM),
  [TD_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_PDOT, KC_COLN),
  [TD_LPN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_L, reset_L),
  [TD_RPN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_R, reset_R),
  [TD_SLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_slash, reset_slash),
  [TD_DSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_dash, reset_dash),
  [TD_LGN] = ACTION_TAP_DANCE_FN (tap_dance_login)
};