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
    -
