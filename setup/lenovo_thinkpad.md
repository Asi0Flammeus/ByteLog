# Set configuration for my laptop

Will log all steps to get my configuration for daily workflows.

## Initial steps

- Boot ubuntu 20 and encrypt disk
- then canonical command to update (refused to upgrade to 24 because of firmware bug of ThinkPad14s)

```
sudo apt update
sudo apt upgrade
sudo snap nvim --classic
sudo apt curl stow htop
```

## Get credential and setup git

### Bitwarden

```
sudo snap install bitwarden
```

(need 2FA from Aegis, would be nice to learn how 2FA works)

- set dark mode obviously

### SSH and PGP keys

- got no better way to simply copy-paste from another device with them via bitwarden

```
chmod 600 ~/.ssh/id_ed25519
chmod 644 ~/.ssh/id_ed25519.pub
sudo chown -R asi0:asi0 ~/.ssh/
eval "$(ssh-agent -s)"
```

- test with a github repo

```
sudo apt install git git@github.com:Asi0Flammeus/dotfiles.git

```
- then install all the github repos but more important one is `.dotfiles` for config, but install it not in the dedicated folder for repos but in the home folder.

### Dotfile config and stow

- source: https://www.youtube.com/watch?v=y6XCebnB9gs
- install stow

```
sudo apt install stow
cd ~/dotfiles/
stow .
```



## Setup minimal config for terminal and nvim


### Install Alacritty

```
sudo add-apt-repository ppa:aslatter/ppa
sudo apt update
sudo apt install alacritty
```


### add lazy.lua bootstrap 

```
-- Bootstrap lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable",
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

```
- then run nvim and let the lazylua config run
- install python3 
```
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt install python3.9
sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.9 1
sudo ln -sf /usr/bin/python3.9 /usr/bin/python3
sudo apt install python3.9-distutils
sudo apt install python3.9-venv python3.9-dev python3-pip
```
### Install ZSH

- dont know I have install zsh and 
```
sudo apt install zsh
chsh -s $(which zsh)
```
then logout and log in
- and source the config file

### Install lazygit

```
LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | grep '"tag_name":' |  sed -E 's/.*"v*([^"]+)".*/\1/')
curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/latest/download/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz"
sudo tar xf lazygit.tar.gz -C /usr/local/bin lazygit
rm lazygit.tar.gz
```
### install exa and zoxide

```
sudo apt install cargo  # Install Rust's package manager
cargo install exa
cargo install zoxide
```
### install p10k configuration

```
mkdir -p ~/.local/share/fonts
# MesloLGS NF fonts (required for p10k)
wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Regular.ttf -P ~/.local/share/fonts/
wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Bold.ttf -P ~/.local/share/fonts/
wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Italic.ttf -P ~/.local/share/fonts/
wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Bold%20Italic.ttf -P ~/.local/share/fonts/
sudo apt install fonts-font-awesome
fc-cache -f -v
```
