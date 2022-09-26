" Plugins will be downloaded under the specified directory.
call plug#begin('~/.vim/plugged')

" Declare the list of plugins.
Plug 'tpope/vim-sensible'

Plug 'vimwiki/vimwiki'

Plug 'junegunn/seoul256.vim'

" On Demand
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }

"Github Syntax Highlighting
Plug 'cormacrelf/vim-colors-github'

"Airline
Plug 'vim-airline/vim-airline'

"Two FireWatches
Plug 'rakr/vim-two-firewatch'

Plug 'ayu-theme/ayu-vim'

"Plug 'iamcco/markdown-preview.nvim', { 'do':{ ->mkdp#util#install() }, 'for': ['markdown', 'vim-plug']}   

"Writing Latex
Plug 'lervag/vimtex'

"List ends here. Plugins become visible to Vim after this call.
call plug#end()

syntax off

"set background=light
"let g:two_firewatch_italics=1
"colo two-firewatch
set cb=unnamed

"let g:airline_theme='twofirewatch'

set termguicolors
"colorscheme blue
"let ayucolor="dark"
"colorscheme ayu

au GUIEnter * simalt ~x
set hls
set ts=4
"set guifont=Fixedsys:h16
set guifont=Consolas:h14
set sw=4
set si
set cindent
set noundofile
set nobackup
set nu

set autochdir

"cd C:\Users\Kevin Miao\projects
cd D:\codes

map <C-n> :NERDTreeToggle<CR>

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

autocmd filetype c nnoremap <S-F8> :w <bar> !gcc % -o %:r<CR>
autocmd filetype c nnoremap <S-F9> :!%:r<CR>
autocmd filetype c nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $


autocmd filetype cpp nnoremap <S-F8> :w <bar> !g++ -std=c++14 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <S-F9> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

autocmd filetype python nnoremap <S-F9> :w <bar> !py %<CR>

augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction

func SetTips()
let l = 0
let l = l + 1 | call setline(l,'// Author		:K1yu#0224')
let l = l + 1 | call setline(l,'// Created Time	:'.strftime('%c'))
let l = l + 1 | call setline(l,'/* stuff you should look for')
let l = l + 1 | call setline(l,'	* read the problem carefully before implmenting')
let l = l + 1 | call setline(l,'	* try to mannually simulate when you do not understand')
let l = l + 1 | call setline(l,'	* DO NOT GET STUCK ON ONE APPROACH')
let l = l + 1 | call setline(l,'*/')
endfunc

map <F2> <F3> 8j<CR>
map <F3> :call SetTips()<CR>
func SetTitle()
let l = 0
let l = l + 1 | call setline(l,'// Author        :zqsml')
let l = l + 1 | call setline(l,'// Created Time  :'.strftime('%c'))
let l = l + 1 | call setline(l,'#include <bits/stdc++.h>')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'using ll = long long;')
let l = l + 1 | call setline(l,'using db = double;')
let l = l + 1 | call setline(l,'using str = string;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'using pi = pair<int,int>;')
let l = l + 1 | call setline(l,'using pl = pair<ll,ll>;')
let l = l + 1 | call setline(l,'using pd = pair<db,db>;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'using vi = vector<int>;')
let l = l + 1 | call setline(l,'using vb = vector<bool>;')
let l = l + 1 | call setline(l,'using vl = vector<ll>;')
let l = l + 1 | call setline(l,'using vd = vector<db>;')
let l = l + 1 | call setline(l,'using vs = vector<str>;')
let l = l + 1 | call setline(l,'using vpi = vector<pi>;')
let l = l + 1 | call setline(l,'using vpl = vector<pl>;')
let l = l + 1 | call setline(l,'using vpd = vector<pd>;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'/* To be completed after learning Template */')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'// pairs')
let l = l + 1 | call setline(l,'// #define mp make_pair')
let l = l + 1 | call setline(l,'// use {a, b} now instead')
let l = l + 1 | call setline(l,'#define f first')
let l = l + 1 | call setline(l,'#define s second')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'// vectors')
let l = l + 1 | call setline(l,'// size(x), rbegin(x), rend(x) need C++17')
let l = l + 1 | call setline(l,'#define sz(x) int((x).size())')
let l = l + 1 | call setline(l,'#define bg(x) begin(x)')
let l = l + 1 | call setline(l,'#define all(x) bg(x), end(x)')
let l = l + 1 | call setline(l,'#define rall(x) x.rbegin(), x.rend()')
let l = l + 1 | call setline(l,'#define sor(x) sort(all(x))')
let l = l + 1 | call setline(l,'#define rsz resize')
let l = l + 1 | call setline(l,'#define ins insert')
let l = l + 1 | call setline(l,'#define ft front()')
let l = l + 1 | call setline(l,'#define bk back()')
let l = l + 1 | call setline(l,'#define pb push_back')
let l = l + 1 | call setline(l,'#define eb emplace_back')
let l = l + 1 | call setline(l,'#define pf push_front')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'#define lb lower_bound')
let l = l + 1 | call setline(l,'#define ub upper_bound')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'// loops')
let l = l + 1 | call setline(l,'#define REP(i,a,b) for (int i = (a); i < (b); ++i)')
let l = l + 1 | call setline(l,'#define FOR(i,a) REP(i,0,a)')
let l = l + 1 | call setline(l,'#define PER(i,a,b) for(int i = (b)-1; i >= (a); --i)')
let l = l + 1 | call setline(l,'#define ROF(i, a) PER(i,0,a)')
let l = l + 1 | call setline(l,'#define rep(a) FOR(_,a)')
let l = l + 1 | call setline(l,'#define each(a,x) for (auto& a : x)')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'const int MOD = 1e9+7;')
let l = l + 1 | call setline(l,'const int MX = 2e5+5;')
let l = l + 1 | call setline(l,'const int inf = 0x3f3f3f3f;')
let l = l + 1 | call setline(l,'const ll INF = 1e18;')
let l = l + 1 | call setline(l,'const db PI = acos((db)-1);')
let l = l + 1 | call setline(l,'const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'/* Many Codes Skipped */')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'inline namespace FileIO {')
let l = l + 1 | call setline(l,'	void setIn(str s) {freopen(s.c_str(),"r",stdin);}')
let l = l + 1 | call setline(l,'	void setOut(str s) {freopen(s.c_str(),"w",stdout);}')
let l = l + 1 | call setline(l,'	void setIO(str s = ""){')
let l = l + 1 | call setline(l,'		cin.tie(0)->sync_with_stdio(0);	// unsync C / C++ I/O streams')
let l = l + 1 | call setline(l,'		// cin.exceptions(cin.failbit);')
let l = l + 1 | call setline(l,'		// throws exception when do smth illegal')
let l = l + 1 | call setline(l,'		// ex. try to read letter into int')
let l = l + 1 | call setline(l,'		if (sz(s)) setIn(s+".in"), setOut(s+".out");	// for old USACO')
let l = l + 1 | call setline(l,'	}')
let l = l + 1 | call setline(l,'}')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main(){')
let l = l + 1 | call setline(l,'	setIO();')
let l = l + 1 | call setline(l,'	')
let l = l + 1 | call setline(l,'	// you should actually read the stuff at the bottom')
let l = l + 1 | call setline(l,'}')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'/* stuff you should look for')
let l = l + 1 | call setline(l,'		* int overflow, array bounds')
let l = l + 1 | call setline(l,'		* special cases(n=1?)')
let l = l + 1 | call setline(l,'		* do smth instead of nothing and stay organized')
let l = l + 1 | call setline(l,'		* WRITE STUFF DOWN')
let l = l + 1 | call setline(l,'		* DONT GET STUCK ON ONE APPROACH')
let l = l + 1 | call setline(l,'*/')
endfunc

"Setting for vimtex
set encoding=utf-8
"
let g:tex_flavor='latex'

let g:vimtex_view_general_viewer='SumatraPDF'
let g:vimtex_view_general_options_latexmk='-reuse-instance'
let g:vimtex_view_general_options
\ = '-reuse-instance -forward-search @tex @line @pdf'
\ . ' -inverse-search "' . exepath(v:progpath)
\ . ' --servername ' . v:servername
\ . ' --remote-send \"^<C-\^>^<C-n^>'
\ . ':execute ''drop '' . fnameescape(''\%f'')^<CR^>'
\ . ':\%l^<CR^>:normal\! zzzv^<CR^>'
\ . ':call remote_foreground('''.v:servername.''')^<CR^>^<CR^>\""'

set conceallevel=1
let g:tex_conceal='abdmg'

"Setting for Vim-wiki
set nocompatible
filetype plugin on
syntax on
