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

syntax on
colorscheme monokai

au GUIEnter * simalt ~x
set hls
set ts=4
set sw=4
set guifont=Dejavu_Sans_Mono:h12
set si
set cindent
set noundofile
set nobackup
set nu
set cb=unnamed

set autochdir

cd D:\codes

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

autocmd filetype c nnoremap <C-A> :w <bar> !gcc % -o %:r<CR>
autocmd filetype c nnoremap <C-S> :!%:r<CR>
autocmd filetype c nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

autocmd filetype cpp nnoremap <C-A> :w <bar> !g++ -std=c++14 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <C-S> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

autocmd filetype python nnoremap <C-S> :w <bar> !py %<CR>

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

autocmd filetype cpp nnoremap <C-E> :call SetTips()<CR>

func CF()
let l = 0
let l = l + 1 | call setline(l,'// Author:	Kexuan Miao')
let l = l + 1 | call setline(l,'// Time:	'.strftime('%c'))
let l = l + 1 | call setline(l,'#include <bits/stdc++.h>')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'using ll = long long;')
let l = l + 1 | call setline(l,'using vi = vector<int>;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'void solve() {')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'}')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main() {')
let l = l + 1 | call setline(l,'	cin.tie(0)->sync_with_stdio(0);')
let l = l + 1 | call setline(l,'	cin.exceptions(cin.failbit);')
let l = l + 1 | call setline(l,'	int t;')
let l = l + 1 | call setline(l,'	cin >> t;')
let l = l + 1 | call setline(l,'	while (t--) {')
let l = l + 1 | call setline(l,'		solve();')
let l = l + 1 | call setline(l,'	}')
let l = l + 1 | call setline(l,'	return 0;')
let l = l + 1 | call setline(l,'}')
endfunc

"Hotkey for generating template
"Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/contest/template.cpp
func SetTips()
let l = 0
let l = l + 1 | call setline(l,'// Author:	Kexuan Miao')
let l = l + 1 | call setline(l,'// Time:	'.strftime('%c'))
let l = l + 1 | call setline(l,'#include <bits/stdc++.h>')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'#define LSOne(S) ((S) & -(S))')
let l = l + 1 | call setline(l,'#define all(x) begin(x), end(x)')
let l = l + 1 | call setline(l,'#define sz(x) (int)(x).size()')
"let l = l + 1 | call setline(l,'#define f first')
"let l = l + 1 | call setline(l,'#define s second')
"let l = l + 1 | call setline(l,'#define pb push_back')
"let l = l + 1 | call setline(l,'#define trav(a,x) for (auto& a: x)')
let l = l + 1 | call setline(l,'using ll = long long;')
let l = l + 1 | call setline(l,'using vi = vector<int>;')
let l = l + 1 | call setline(l,'using pii = pair<int, int>;')
let l = l + 1 | call setline(l,'using vii = vector<pii>;')
let l = l + 1 | call setline(l,'const int MOD = 1e9+7;')
let l = l + 1 | call setline(l,'const int INF = 0x3f3f3f3f;')
let l = l + 1 | call setline(l,'const double EPS = 1e-9;')
"let l = l + 1 | call setline(l,'const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // grid problems')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main() {')
let l = l + 1 | call setline(l,'	cin.tie(0)->sync_with_stdio(0);')
let l = l + 1 | call setline(l,'	cin.exceptions(cin.failbit);')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'	return 0;')
let l = l + 1 | call setline(l,'}')
endfunc
