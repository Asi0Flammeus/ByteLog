# Set configuration for my laptop

Will log all steps to get my configuration for daily workflows.

## Initial steps

- Boot ubuntu 20 and encrypt disk
- then canonical command to update (refused to upgrade to 24 because of firmware bug of ThinkPad14s)

```
sudo apt update
sudo apt upgrade
sudo snap nvim --classic
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
sudo apt install git

```

## Setup minimal config for terminal and nvim

##
