## 42sh (Complete C Shell)
  
  This project was developped by 5 awesome guys (well, almost):
  
    Felix RAHIL : Built the history file (easy)
    Nicolas TROGNOT : Developped the binary tree and minor debug
    Alexis PAPADIMITRIOU : Did the almost finished operators implementation using LL parsing (not working atm)
    Côme GRELLARD : Worked on the users features with me like bashrc , aliasing
    Me : Built the data structure and shell core. Also added globbing and others cool features to the project
    
You can use this shell like any other shell you are used to .

Pipes work but doesn't close themselves properly, resulting in an infinite loop...

    To use it : make re && ./42sh
    
    Start with "source .42shrc" to add your custom commands
    
    Builtins : echo, setenv, unsetenv, exit, env, alias, source
    
Options : 

>Globbing (ls *)

>Bashrc like (config file : .42shrc)

>History file (.42sh_history)

>Env variables (echo $PATH)

>Alias commands (alias ls ls --color=auto)

  
