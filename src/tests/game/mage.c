/* game/mage.c */

#include "unit-test.h"
#include "unit-test-data.h"
#include "test-utils.h"

#include <stdio.h>
#include "cave.h"
#include "cmd-core.h"
#include "game-event.h"
#include "game-world.h"
#include "generate.h"
#include "init.h"
#include "mon-make.h"
#include "savefile.h"
#include "player.h"
#include "player-birth.h"
#include "player-timed.h"
#include "z-util.h"

static void event_message(game_event_type type, game_event_data *data, void *user) {
	printf("Message: %s\n", data->message.msg);
}

static void println(const char *str) {
	printf("%s\n", str);
}

int setup_tests(void **state) {
	/* Register a basic error handler */
	plog_aux = println;

	/* Register some display functions */
	event_add_handler(EVENT_MESSAGE, event_message, NULL);
	event_add_handler(EVENT_INITSTATUS, event_message, NULL);

	/* Init the game */
	set_file_paths();
	init_angband();

	return 0;
}

int teardown_tests(void *state) {
	file_delete("Test1");
	wipe_mon_list(cave, player);
	cleanup_angband();
	return 0;
}

static int test_magic_missile(void *state) {

	/* Try making a new game */
	eq(player_make_simple("Gnome", "Mage", "Tyrion"), true);

	eq(player->is_dead, false);
	prepare_next_level(player);
	on_new_level();
	notnull(cave);
	eq(player->chp, player->mhp);
	eq(player->timed[TMD_FOOD], PY_FOOD_FULL - 1);

	cmdq_push(CMD_STUDY);
	cmd_set_arg_choice(cmdq_peek(), "spell", 0);
	run_game_loop();
	cmdq_push(CMD_CAST);
	cmd_set_arg_choice(cmdq_peek(), "spell", 0);
	cmd_set_arg_target(cmdq_peek(), "target", 2);
	run_game_loop();
	noteq(player->csp, player->msp);

	ok;
}

const char *suite_name = "game/mage";
struct test tests[] = {
	{ "magic_missile", test_magic_missile },
	{ NULL, NULL }
};
