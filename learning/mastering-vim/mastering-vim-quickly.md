# Mastering Vim Quickly notes

## Why ?

- vim is a powerful language to master for editing file
- as programming is 20% coding and 80% editing, you better get gud at editing
- why vim is powerful ?
  - had its own syntax that is vim motion
  - it can be fune-tuned to our specific needs
- vim is not beginner-friendly so the learning curve is stiff

> Don't wish Vim was easier, wish you were better! (p.6)

As the creator of Vim, Bram Moolenaar puts it:

> Learning to drive a car takes effort. Is that a reason to keep driving a bicycle? No, you realize you need to invest time to learn a skill. Text editing isn't different. You need to learn new commands and turn them into habit.

- to learn this new habit, we can't rely on sole motivation and will-power, simply because there are not reliable for long term discipline.
  - instead use "mini-habits", like
    - pass a moment daily on practicing new commands that corresponds to you need
    - keep a reccord of what is difficult to do in vim, and do from time to time some drilling exercice on it.
    - personnaly, I use nvim as my principal and only editor so I have to use it every single time I want to write a note or code.
      - here the underlying principle is use meaningful friction to incite you to practice your new habit.

## Vim Basics

- to close and update a file, use the command `ZZ` which is equivalent to `:x`
- word =/= WORD:
  - word (w) stops at each delimiter
  - Word (W) only stops to space delimiter
- most of the time vim motions are defined by the initial letter of the corresponding actions or object
- `ctrl+ d,u,f,b` allows us to navigate though the file (down, up, full-page, beginning)
  - fun way also is to enter a percentage to jump at the portion of the file, eg. `50%`
- vim is used in different modes: normal, insert and view
  - if you want to do insert -> normal for 1 command -> insert, then use `ctrl+o`
- you can have an powerful search using `*` or `#` if you looking for the word under the cursor

## Vim Syntax

- a vim action syntax is `<verb><modifier><nouns>`
  - verbs
    - powerless (apply on 1 character)
      - `x`: delete 1 character
      - `c`: replace 1 character
      - `s`: delete 1 character + insert mode
      - `a`: append
        - `A`: append to the end of the line
      - `i`: go insert mode
    - powerful (apply on any object)
      - y: yank
      - d: delete
      - c: change
      - v: visualy select
  - modifier
    - i: inner
    - a: around
    - <NUM>: number as a mutlipier
    - t: until forward
      - T: until backward
    - f: find forward
      - F: find backward
    - /: find expression forward
      - ?: find expression backward
  - noun
    - w, W: the next word
    - b, B: the word before
    - e: the end of word
    - s: the sentence
    - $: the end of the line
    - ^, 0: the begining of the line
    - p: the paragraph
    - %: the matching symbols (), [], {}, '', ""
    - t: the html tag
    - b: the block
    - h,j,k,l: left, up, down, right
- before any noun a range can be added
  - <NUM>: the line number
  - $: the last line
  - %: all the lines
  - <NUM>,<NUM>: line number of inclusive interval
  - .: the current line
  - +<NUM>,+<NUM>: relative line number of inclusive interval (works with - too)
  - ?foo?,/bar: inclusive interval define by the lines that contains foo and bar
- range is quite useful for search and replace command
  - `[range] s/foo/bar/[flags] [count]`
    - flags
      - c: confirmation for each substitute
      - g: replace all
      - i: ignore case for pattern
      - I: don't ignore case for pattern
    - the range can also be selected in visual mode
      - v + select lines + type `:,`
    - if want to replace specifically a word and not the pattern use
      - `:s/\word\/new word/g`
    - if you want to replace multiple strings at once use
      - `s/\(word 1 | word 2)\/new word/g`
- the global command could be quite powerful
  - `:[range]g/pattern/cmd` with cmd as the command you want to apply on the rangge
  - eg. remove all blank lines
    - `:g/^\s*$/d`
- the move cmd
  - `:[range]m<NUM>` move range lines to NUM line
  - `:[range]t<NUM>` copy range lines to NUM line

## Registers

- Registers are quite important to understand as they can be quite powerful because they extend a lot the copy/paste functionalities
- a register is simply memory allocation for text
- use `ctrl-r` in insert mode to call them
  - can be used in command mode too
    - for eg. `:s/ctrl-r + reg/bar/g`
- [website](https://www.baeldung.com/linux/vim-registers) for further info
- there's a shit tone of registers accessible in vim divided into several types
  - unnamed, `""`
    - used per default when delete or yank
  - numbered, `"0` to `"9`
    - last yank goes to `"0`
  - letter named, `"a` to `"z` or `"A` to `"Z`
    - customed clipboard for handling multiple yanks at the same time
    - lower and upper case register refer to the same text, just when yank to uppercase, it append to the already present text, whereas with lower case it replaces it
  - small delete, `"-`
    - any lesser than a line and is deleted goes here
  - expression, `:.`
    - last thing you have entered in inser mode goes here
    - all the keys from the insertion in that mode to back to normal
    - when typing `..` in normal mode it calls this reg
  - command, `":`
    - last expression used goes here
  - black hole, `"_`
  - last search pattern, `"/`
  - selection and drop, `"*`, `"+`, `"-`
    - `"*` and `"+` are used for copy from vim to external and external to vim, respectively
      - not necessary with nvim and plugin
  - current filpath register, `"%`
  - alternative file, `"#`
    - consider it as last file name
- the syntax is `<register_name><vim action>`
  - for eg. `"ayy` to copy line in `"a` register
- to recall what's in any register run `:reg(ister)`

## Buffers

- buffer = in-memory text of a file
- vim = tab $\subset$ window $\subset$ buffer
- use `:ls` to list buffers and `:bp` to cycle through them
- mostly use to edit mutliple files at the same time
  - personal opinion: I find it easier to open another terminal pane and use bash commands to edit multiple files
- the use of buffers is less needed when using nvim because with plugin like telescope, one can reach easily in files

## Macros

- macros = recording of a sequence of actions
- to record one use `q<register><actions>q` in normal mode
  - note that you can have multiple macros with the use of several reg (from a to z)
- to execute a macro use `@<register>`
  - last macro with `@@`
  - N time the last macro, `<NUM>@`
- enable `lazyredraw` if you want to apply a macro more than a thousands to avoid displaying on screen
- macros can be applied to multiple file by using args
  - load files in args, `:args path/to/files/*.md`
  - run macro, `:argdo normal @<reg>`
  - save in all buffers, `:argdo update`
- edit a macro simply paste the corresponding reg on a line, edit it and then copy back to the reg with `0<reg>y$` (can't use `yy` because it will add a breakline)
- macros will be recursived if the reg used is empty

## Visual mode

- `V`, let you visualy select a whole line
- you can apply any vim action to selected lines with `:normal <action>`
  - eg. `:normal A;` to append `;` at the end of the lines
  - use `%normal` if you want it to be applied to the entire file
- add specific remap to have `J` and `K` that move the selected lines up or down
  - with nvim maybe use this pluggin: https://github.com/echasnovski/mini.nvim

## Remaping

- remap can be recursive, which means that it changes the behavior even in the config file
  - by default you should use non-recursive mapping, except when explicitly needed
- `:map` = recursive, `noremap` = non-recursive, `unmap` = unmapping
- prefixes are used to declare the mode in which it is applied
  - no prefix: normal, visual, operator-pending
  - `nmap`: normal
  - `xmap`: visual
  - `imap`: insert
  - `cmap`: command-line
  - `omap`: operator-pending
- use the key `<nop>` to disable a key

## Folding

- use in normal mode `zf<noum>` to fold a portion of the file
- not sure how to properly unfold

## Effective multiple file editing

- I prefer to use bash commands to edit multiple files at the same
  - but maybe it is just a skill issue
- the `w` and `up` command are different
  - `w` always edit the file even though no modification was done
  - `up` only save if the file has been modified
- do `:args` to get the list of arguments files
  - `:args [path]` to add all files in path to arglist

## Productivity tips

- autocomplete by vim
  - in insert mode do `ctlr+x` with the corresponding dictionnary
    - `ctrl+I`, complete whole lines of text
    - `ctrl+i`, complete words from included files
    - `ctrl+t`, complete words from thesaurus
      - to set this dictionnary you have to set the `thesaurus.txt` file
        - `set thesaurus+=[path-to-thesaure-txt-file]`
      - useful to replace a word by its synonyms
