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
badd +1 ~/Desktop/repos/diploma/src/view/view.cpp
badd +9 ~/Desktop/repos/diploma/.clangd
badd +10 ~/Desktop/repos/diploma/inc/parser/parser.hpp
badd +12 ~/Desktop/repos/diploma/inc/model/population.hpp
badd +9 ~/Desktop/repos/diploma/inc/model/model.hpp
badd +19 ~/Desktop/repos/diploma/src/parser/parser.cpp
badd +18 ~/Desktop/repos/diploma/inc/types.hpp
badd +1 ~/Desktop/repos/diploma/inc/core/icrossover.hpp
badd +9 ~/Desktop/repos/diploma/inc/core/ifitness.hpp
badd +2 ~/Desktop/repos/diploma/diploma.pro
badd +9 ~/Desktop/repos/diploma/src/main.cpp
badd +1 ~/Desktop/repos/diploma/test/core/CMakeLists.txt
badd +3 ~/Desktop/repos/diploma/test/model/test_model.cpp
badd +8 ~/Desktop/repos/diploma/inc/model/cell.hpp
badd +16 ~/Desktop/repos/diploma/inc/model/chromosome.hpp
badd +1 ~/Desktop/repos/diploma/CMakeLists.txt
badd +28 ~/Desktop/repos/diploma/src/model/population.cpp
badd +13 ~/Desktop/repos/diploma/inc/core/fitness_manhattan.hpp
badd +12 ~/Desktop/repos/diploma/inc/core/editor/editor.hpp
badd +11 ~/Desktop/repos/diploma/src/core/editor/editor.cpp
badd +7 ~/Desktop/repos/diploma/inc/core/crossover/crossover_two_point.hpp
badd +8 ~/Desktop/repos/diploma/inc/core/crossover/icrossover.hpp
badd +12 ~/Desktop/repos/diploma/inc/core/fitness/fitness_manhattan.hpp
badd +9 ~/Desktop/repos/diploma/inc/core/fitness/ifitness.hpp
badd +12 src/core/fitness/fitness_manhattan.cpp
badd +6 ~/Desktop/repos/diploma/src/core/crossover/crossover_two_point.cpp
badd +49 ~/Desktop/repos/diploma/src/model/chromosome.cpp
badd +17 src/model/cell.cpp
argglobal
%argdel
edit src/core/fitness/fitness_manhattan.cpp
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
balt ~/Desktop/repos/diploma/inc/model/cell.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 12 - ((11 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 12
normal! 032|
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
