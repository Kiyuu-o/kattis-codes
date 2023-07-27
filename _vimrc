" Plugins will be downloaded under the specified directory.
"call plug#begin('~/.vim/plugged')

" On Demand
"Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }

"Airline
"Plug 'vim-airline/vim-airline'

"Plug 'iamcco/markdown-preview.nvim', { 'do':{ ->mkdp#util#install() }, 'for': ['markdown', 'vim-plug']}   

"Writing Latex
"Plug 'lervag/vimtex'

"List ends here. Plugins become visible to Vim after this call.
"call plug#end()

language en_US.utf8
set cin aw ai is ts=4 sw=4 tm=50 nu noeb ru
sy on   |   im jk <esc>   |   im kj <esc>   |   no ; :
set backspace=indent,eol,start
set guifont=Consolas:h12
set noswapfile
set noundofile
set cb=unnamed
autocmd BufEnter * silent! lcd %:p:h
set cul
cd %:h

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

"Mappings for compile / run / comment
autocmd filetype c nnoremap <C-A> :w <bar> !gcc % -o %:r<CR>
autocmd filetype c nnoremap <C-S> :!%:r<CR>
autocmd filetype c nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

autocmd filetype cpp nnoremap <C-A> :w <bar> !g++ -std=c++2a % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <C-S> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

autocmd filetype python nnoremap <C-S> :w <bar> !py %<CR>

augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

autocmd filetype cpp nnoremap <C-E> :call SetTips()<CR>
autocmd filetype tex nnoremap <C-E> :!pdflatex %<CR>

"CodeForces Practice Snippet
func CF()
let l = 0
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

"General Purpose Snippet
"Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/contest/template.cpp
func SetTips()
let l = 0
let l = l + 1 | call setline(l,'#include <bits/stdc++.h>')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'#define LSOne(S) ((S) & -(S))')
let l = l + 1 | call setline(l,'using ll = long long;')
let l = l + 1 | call setline(l,'using vi = vector<int>;')
let l = l + 1 | call setline(l,'using pii = pair<int, int>;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main() {')
let l = l + 1 | call setline(l,'	cin.tie(0)->sync_with_stdio(0);')
let l = l + 1 | call setline(l,'	cin.exceptions(cin.failbit);')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'	return 0;')
let l = l + 1 | call setline(l,'}')
endfunc
