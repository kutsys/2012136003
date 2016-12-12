# ~/.bashrc: executed by bash(1) for non-login shells.
~/.bashrc: ��α��� ������ ���� bash(1)�� ���� �����Ѵ�.

# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
/usr/share/doc/bash/examples/startup-files�� ���ƶ�. (bash-doc ��Ű�� �ȿ� �ִ�)

# for examples
���� ���

# If not running interactively, don't do anything
���� ��ȣ�ۿ��ϸ� ������� �ʴ´ٸ�, �ƹ��͵� ��������.

case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
�����丮 �ȿ� �ߺ��� line�̳� �������� �����ϴ� line�� ���� ����.

# See bash(1) for more options
�� ���� �ɼǿ� ���ؼ��� bash(1)�� �����϶�.

HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
�����丮 ���Ͽ� ����� �ʰ� �߰��϶�.

shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
�����丮 ���� ������ ���� bash(1) ���� HISTISIZE�� HISTFILESIZE�� ���ƶ�.

HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
������ ��ɾ� ���Ŀ� ������ ����� Ȯ���ϰ�, ���� �ʿ��ϴٸ�,

# update the values of LINES and COLUMNS.
��� ���� ���� ������Ʈ�ض�.

shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
�����ߴٸ�, �н����� Ȯ�� ���ƿ� ���Ǵ� ��**�� ������ 

# match all files and zero or more directories and subdirectories.
��� ����, 0�� Ȥ�� �� �̻��� ���丮��� ������丮��� ��ġ�� ���̴�.

#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
���ؽ�Ʈ �Է� ���ϵ鿡 ���� less�� �� �� ģ���ϰ� ����� ���ؼ� lesspipe(1)�� �����϶�.

[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
(������Ʈ �Ͽ� ���Ǵ�) �۾��ϰ� �ִ� chroot�� �ĺ��ϴ� ������ �����϶�.

if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
ȭ���� ���� �����϶�. (���� �ϰ� ���ϴ� ���� ���ٸ� ���� ������ �Ѵ�.)

case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
���� �͹̳��� �����ϴٸ� ���� ������ ������Ʈ�� ���� �ڸ�Ʈ�� �����ʴ´�.

# off by default to not distract the user: the focus in a terminal window
����ڿ��� ȥ���� ���� �ʱ� ���� �⺻���� �����ض�: �͹̳� â������ ������

# should be on the output of commands, not on the prompt
������Ʈ�� �ƴ� ����� ������� �־���Ѵ�.

#force_color_prompt=yes
if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then

	# We have color support; assume it's compliant with Ecma-48
�츮�� ������ ������ �� �ִ�; Ecma-48�� �����ϴٰ� ��������.

	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
(ISO/IEC-6429). (�׷��� ������ ������ ���� �幰��, �׷���

	# a case would tend to support setf rather than setaf.)
���̽��� setf���� setaf�� �����ϴ� ������ �ִ�.)

	color_prompt=yes
    else
	color_prompt=
    fi
fi
if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
���� �̰��� xterm�� ��� ������ user@host:dir�� �����϶�.

case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
ls�� �� ������ �����ϰ� �ϰ�, ���� ���ܸ� ��ɾ �߰��϶�.

if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
GCC���� ������ ��ĥ�϶�

#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
�� ���� ls aliases

alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
���� �����ϴ� ����� ���� "alert" ��ɾ �߰��϶�. ��ó��:

#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
��ɾ� ���ǵ�

# You may want to put all your additions into a separate file like
�ʴ� �߰� ���׵��� ~/.bash_aliases ���� �и��� ���Ͽ� �ִ� ���� ������ �𸥴�.

# ~/.bash_aliases, instead of adding them here directly.
���⿡ ���� �� �߰� ���׵��� �߰��ϴ� ��ſ�

# See /usr/share/doc/bash-doc/examples in the bash-doc package.
bash-doc ��Ű�� �ȿ� �ִ� /usr/share/doc/bash-doc/examples�� ���ƶ�.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
��밡���ϸ� ���α׷����� ������ Ư¡ (�ʴ� �̰��� ����ϰ� �� �ʿ�� ����.

# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
���� /etc/bash.bashrc�� /etc/profile���� ����� �� �ִٸ�)

# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

PS1 = "[\u @\w]\\$"