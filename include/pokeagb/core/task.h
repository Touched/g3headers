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
  typedef void (*TaskCallback)(u8 id);

  /** A short-lived background function with state.
   */
  struct Task {
    TaskCallback function; /**< Function to run */
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
  LONG_CALL u8 task_add(TaskCallback func, u8 priority);

  /** Delete a task.
   */
  LONG_CALL void task_del(u8 id);

  LONG_CALL void task_exec(void);

  /** All the tasks.
   */
  extern struct Task tasks[16];

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_CORE_TASK_H_ */
