# Troubleshooting

## Cannot run any binary with ncurses

Some users have the following error when running a ncurses app:

```bash
Error opening terminal: xterm-256color.
make: *** [Makefile:62: run] Error 1
```

This happen because ncurses cannot find terminfo. You can look into your computer
for the terminal info running command `locate terminfo`, or executing `infocmp`
binary. The last command will generate an output like this:

```bash
#	Reconstructed via infocmp from file: /usr/share/terminfo/x/xterm-256color
...
```

Some users have this info in other paths so look for your path. If you cannot find that,
you may need to install `ncurses-term` package. When you know where the terminfo folder
is, just export a environment variable:

```bash
export TERMINFO=/home/vgonisanz/.terminfo
```

This solution is only valid for the current bash session (it is a local environment variable)
but you can add it into .bashrc or .zshrc to avoid re-define every session.
