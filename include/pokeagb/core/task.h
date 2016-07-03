/*
 * This file is part of PokeAGB.
 *
 * PokeAGB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PokeAGB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PokeAGB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef POKEAGB_CORE_TASK_H_
#define POKEAGB_CORE_TASK_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>

#ifdef __cplusplus
extern "C" {
#endif

  /**Task function.
   * @param id The ID of the the current task
   */
  typedef void (*task_callback)(u8 id);

  /** A short-lived background function with state.
   */
  struct task {
    task_callback function; /**< Function to run */
    bool inuse;
    u8 prev;
    u8 next;
    u8 priority;
    u16 priv[16]; /**< State variables */
  };

  /** Start a new task.
   * @param func Function pointer
   * @return Task ID
   */
  LONG_CALL u8 task_add(task_callback func, u8 priority);

  /** Delete a task.
   */
  LONG_CALL void task_del(u8 id);

  LONG_CALL void task_exec(void);

  /** All the tasks.
   */
  extern struct task tasks[16];

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_TASK_H_ */
