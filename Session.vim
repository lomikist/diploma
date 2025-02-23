let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Desktop/repos/diploma
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +12 ~/Desktop/repos/diploma/inc/types.hpp
badd +4 ~/Desktop/repos/diploma/src/main.cpp
badd +21 inc/core/editor/editor.hpp
badd +21 src/core/editor/editor.cpp
badd +7 inc/core/crossover/crossover_two_point.hpp
badd +9 inc/core/crossover/icrossover.hpp
badd +11 ~/Desktop/repos/diploma/inc/core/fitness/fitness_manhattan.hpp
badd +2 ~/Desktop/repos/diploma/inc/core/fitness/ifitness.hpp
badd +16 src/core/crossover/crossover_two_point.cpp
badd +48 term://~/Desktop/repos/diploma//48464:/usr/bin/fish
badd +33 ~/Desktop/repos/diploma/data/graph_6.txt
badd +12 ~/Desktop/repos/diploma/inc/core/select/select_to_half.hpp
badd +7 src/core/select/select_to_half.cpp
badd +2 test/core/test_twopoint_crossfit.cpp
badd +7 inc/model/cell.hpp
badd +53 src/model/chromosome.cpp
badd +44 CMakeLists.txt
badd +11 inc/core/select/iselect.hpp
badd +2 inc/model/model.hpp
badd +3 ~/Desktop/repos/diploma/inc/model/population.hpp
badd +11 src/parser/parser.cpp
badd +25 test/core/test_fitness.cpp
badd +22 ~/Desktop/repos/diploma/inc/core/app.hpp
badd +1 ~/Desktop/repos/diploma/data/graph_2.txt
badd +319 ~/Desktop/repos/diploma/data/graph_7.txt
badd +12 ~/Desktop/repos/diploma/src/model/cell.cpp
badd +22 inc/model/chromosome.hpp
badd +1 ~/Desktop/repos/diploma/inc/core/utilities.hpp
badd +1 ~/Desktop/repos/diploma/src/core/utilities.cpp
badd +16 ~/Desktop/repos/diploma/.clangd
badd +9 ~/Desktop/repos/diploma/data/graph_1.txt
badd +10 ~/Desktop/repos/diploma/inc/core/mutate/imutate.hpp
badd +9 ~/Desktop/repos/diploma/inc/core/mutate/mutate_random.hpp
badd +2 ~/Desktop/repos/diploma/src/core/mutate/mutate_random.cpp
argglobal
%argdel
edit ~/Desktop/repos/diploma/src/core/mutate/mutate_random.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
silent! normal! zE
let &fdl = &fdl
let s:l = 2 - ((1 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 015|
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
