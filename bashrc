# ~/.bashrc: executed by bash(1) for non-login shells.
~/.bashrc: 비로그인 쉘들을 위해 bash(1)에 의해 실행한다.

# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
/usr/share/doc/bash/examples/startup-files를 보아라. (bash-doc 패키지 안에 있는)

# for examples
예를 들어

# If not running interactively, don't do anything
만약 상호작용하며 실행되지 않는다면, 아무것도 하지마라.

case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
히스토리 안에 중복된 line이나 공백으로 시작하는 line을 넣지 마라.

# See bash(1) for more options
더 많은 옵션에 대해서는 bash(1)를 참고하라.

HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
히스토리 파일에 덮어쓰지 않고 추가하라.

shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
히스토리 길이 설정을 위해 bash(1) 안의 HISTISIZE와 HISTFILESIZE를 보아라.

HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
각각의 명령어 이후에 윈도우 사이즈를 확인하고, 만약 필요하다면,

# update the values of LINES and COLUMNS.
행과 열의 값을 업데이트해라.

shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
설정했다면, 패스네임 확장 문맥에 사용되는 “**” 패턴은 

# match all files and zero or more directories and subdirectories.
모든 파일, 0개 혹은 그 이상의 디렉토리들과 서브디렉토리들과 일치할 것이다.

#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
비텍스트 입력 파일들에 대해 less가 좀 더 친근하게 만들기 위해서 lesspipe(1)를 참고하라.

[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
(프롬프트 하에 사용되는) 작업하고 있는 chroot를 식별하는 변수를 설정하라.

if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
화려한 색을 설정하라.(만약 니가 원하는 색이 없다면 색은 없다)

case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
만약 터미널이 가능하다면 색이 입혀진 프롬프트에 대한 코멘트는 하지않는다.

# off by default to not distract the user: the focus in a terminal window
사용자에게 혼란을 주지 않기 위해 기본값을 해제해라: 터미널 창에서의 초점은

# should be on the output of commands, not on the prompt
프롬프트가 아닌 명령의 결과물에 있어야한다.

#force_color_prompt=yes
if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then

	# We have color support; assume it's compliant with Ecma-48
우리는 색상을 지원할 수 있다; Ecma-48과 부합하다고 가정하자.

	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
(ISO/IEC-6429). (그러한 지원의 부족은 극히 드물고, 그러한

	# a case would tend to support setf rather than setaf.)
케이스는 setf보다 setaf를 지원하는 경향이 있다.)

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
만약 이것이 xterm일 경우 제목을 user@host:dir로 설정하라.

case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
ls의 색 지원을 가능하게 하고, 또한 간단만 명령어도 추가하라.

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
GCC경고와 에러를 색칠하라

#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
더 많은 ls aliases

alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
오래 실행하는 명령을 위해 "alert" 명령어를 추가하라. 이처럼:

#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
명령어 정의들

# You may want to put all your additions into a separate file like
너는 추가 사항들을 ~/.bash_aliases 같은 분리된 파일에 넣는 것을 원할지 모른다.

# ~/.bash_aliases, instead of adding them here directly.
여기에 직접 그 추가 사항들을 추가하는 대신에

# See /usr/share/doc/bash-doc/examples in the bash-doc package.
bash-doc 패키지 안에 있는 /usr/share/doc/bash-doc/examples를 보아라.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
사용가능하며 프로그래밍이 가능한 특징 (너는 이것을 사용하게 할 필요는 없다.

# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
만약 /etc/bash.bashrc나 /etc/profile에서 사용할 수 있다면)

# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

//프롬프트 수정 코드: 사용자 이름과 현재 디렉토리를 나타낸다.
PS1="[\u@ \w]\\$ "
