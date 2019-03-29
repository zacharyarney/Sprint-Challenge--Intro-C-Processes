**1. List all of the main states a process may be in at any point in time on a
standard Unix system. Briefly explain what each of these states means.**
    - Running - Process is currently doing something/active.
    - Waiting - Process is alive but on hold. Like a parent waiting for a child
      fork to finish.
    - Zombie - Process is dead/has ended but hasn't been removed yet.


**2. What is a zombie process?**
    - A zombie process is a process that has finished running and is no longer
      active but also has not been cleaned up yet. Zombie processes can be
      cleaned up via the `wait()` function.


**3. How does a zombie process get created? How does one get destroyed?**
    - Sort of explained above. A zombie process is created when a child process
      (like through a `fork()`) dies. You destroy it by calling `wait()` in the
      parent process. 


**4. What are some of the benefits of working in a compiled language versus a
non-compiled language? More specifically, what benefits are there to be had
from taking the extra time to compile our code?**
    - Compiled languages only need to be translated into machine code once
      making compiled executibles potentially more efficient/faster to run.

