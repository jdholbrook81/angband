#ifndef INCLUDED_CMDS_H
#define INCLUDED_CMDS_H

#include "game-cmd.h"

/* 
 * Command handlers will take a pointer to the command structure
 * so that they can access any arguments supplied.
 */
typedef void (*cmd_handler_fn)(cmd_code code, cmd_arg args[]);

/* cmd.c */
extern void cmd_init(void);

/* cmd0.c */
void do_cmd_quit(cmd_code code, cmd_arg args[]);

/* cmd-obj.c */
void do_cmd_uninscribe(cmd_code code, cmd_arg args[]);
void do_cmd_inscribe(cmd_code code, cmd_arg args[]);
void do_cmd_takeoff(cmd_code code, cmd_arg args[]);
void do_cmd_wield(cmd_code code, cmd_arg args[]);
void do_cmd_drop(cmd_code code, cmd_arg args[]);
void do_cmd_use(cmd_code code, cmd_arg args[]);
void do_cmd_refill(cmd_code code, cmd_arg args[]);
void do_cmd_study_spell(cmd_code code, cmd_arg args[]);
void do_cmd_cast(cmd_code code, cmd_arg args[]);
void do_cmd_study_book(cmd_code code, cmd_arg args[]);

void textui_obj_inscribe(object_type *o_ptr, int item);
void textui_obj_examine(object_type *o_ptr, int item);
void textui_obj_drop(object_type *o_ptr, int item);
void textui_obj_wield(object_type *o_ptr, int item);

/* cmd2.c */
void do_cmd_go_up(cmd_code code, cmd_arg args[]);
void do_cmd_go_down(cmd_code code, cmd_arg args[]);
void do_cmd_search(cmd_code code, cmd_arg args[]);
void do_cmd_toggle_search(cmd_code code, cmd_arg args[]);
void do_cmd_open(cmd_code code, cmd_arg args[]);
void do_cmd_close(cmd_code code, cmd_arg args[]);
void do_cmd_tunnel(cmd_code code, cmd_arg args[]);
void do_cmd_disarm(cmd_code code, cmd_arg args[]);
void do_cmd_bash(cmd_code code, cmd_arg args[]);
void do_cmd_alter(cmd_code code, cmd_arg args[]);
void do_cmd_spike(cmd_code code, cmd_arg args[]);
void do_cmd_walk(cmd_code code, cmd_arg args[]);
void do_cmd_jump(cmd_code code, cmd_arg args[]);
void do_cmd_run(cmd_code code, cmd_arg args[]);
void do_cmd_pathfind(cmd_code code, cmd_arg args[]);
void do_cmd_hold(cmd_code code, cmd_arg args[]);
void do_cmd_pickup(cmd_code code, cmd_arg args[]);
void do_cmd_rest(cmd_code code, cmd_arg args[]);
void do_cmd_suicide(cmd_code code, cmd_arg args[]);
void do_cmd_save_game(cmd_code code, cmd_arg args[]);

void do_cmd_alter_aux(int dir);
void textui_cmd_open(void);
void textui_cmd_close(void);
void textui_cmd_tunnel(void);
void textui_cmd_disarm(void);
void textui_cmd_bash(void);
void textui_cmd_alter(void);
void textui_cmd_spike(void);
void textui_cmd_walk(void);
void textui_cmd_jump(void);
void textui_cmd_run(void);
void textui_cmd_rest(void);
void textui_cmd_suicide(void);

/* cmd3.c */
void do_cmd_inven(void);
void do_cmd_equip(void);
void wield_item(object_type *o_ptr, int item, int slot);
void wield_combine_ammo(object_type *o_ptr, int item, int slot);
void do_cmd_destroy(cmd_code code, cmd_arg args[]);
void textui_cmd_destroy(void);
void refill_lamp(object_type *j_ptr, object_type *o_ptr, int item);
void refuel_torch(object_type *j_ptr, object_type *o_ptr, int item);
void do_cmd_target(void);
void do_cmd_target_closest(void);
void do_cmd_look(void);
void do_cmd_locate(void);
void do_cmd_query_symbol(void);
void do_cmd_center_map(void);

/* cmd4.c */
extern void do_cmd_redraw(void);
extern void do_cmd_resize(void);
extern void do_cmd_change_name(void);
extern void do_cmd_message_one(void);
extern void do_cmd_messages(void);
extern void do_cmd_options(void);
extern void do_cmd_pref(void);
extern void do_cmd_note(void);
extern void do_cmd_version(void);
extern void do_cmd_feeling(void);
extern void do_cmd_load_screen(void);
extern void do_cmd_save_screen(void);

/* cmd-misc.c */
void do_cmd_wizard(void);
void do_cmd_try_debug(void);
void do_cmd_try_borg(void);
void do_cmd_quit(cmd_code code, cmd_arg args[]);
void do_cmd_port(void);
void do_cmd_xxx_options(void);
void do_cmd_monlist(void);
void do_cmd_itemlist(void);
void do_cmd_unknown(void);

/* attack.c */
extern void do_cmd_fire(cmd_code code, cmd_arg args[]);
extern void textui_cmd_fire(void);
extern void textui_cmd_fire_at_nearest(void);
extern void do_cmd_throw(cmd_code code, cmd_arg args[]);
extern void textui_cmd_throw(void);

/* store.c */
extern void do_cmd_store(cmd_code code, cmd_arg args[]);
extern void do_cmd_sell(cmd_code code, cmd_arg args[]);
extern void do_cmd_stash(cmd_code code, cmd_arg args[]);
extern void do_cmd_buy(cmd_code code, cmd_arg args[]);
extern void do_cmd_retrieve(cmd_code code, cmd_arg args[]);

/* Types of item use */
typedef enum
{
	USE_TIMEOUT,
	USE_CHARGE,
	USE_SINGLE
} use_type;

/* XXX */
extern int cmp_monsters(const void *a, const void *b);



/* ui-spell.c -- just for now */
void textui_spell_browse(object_type *o_ptr, int item);
void textui_obj_study(object_type *o_ptr, int item);
void textui_obj_cast(object_type *o_ptr, int item);

/* ui-knowledge.c */
extern void textui_browse_object_knowledge(void *obj, const char *name);
extern void textui_knowledge_init(void);
extern void textui_browse_knowledge(void);

#endif

