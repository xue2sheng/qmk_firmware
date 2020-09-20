## Personal mapping

Clone from littlekeyboards Viet Pham (frontdesk@littlekeyboards.zendesk.com). Just clone getting its recursive modules:

```
git clone --recurse-submodule git@github.com:xue2sheng/qmk_firmware.git
``` 

Consult [QMK documentation](https://beta.docs.qmk.fm/tutorial/newbs_getting_started) to configure the environment.

### Deployment
```
make crkbd/rev1:xue2sheng:avrdude
```
or
```
qmk config user.keyboard=crkbd/rev1
qmk config user.keymap=xue2sheng
qmk compile
```

### Pull updates from littlekeyboards
```
git remote add upstream git@github.com:littlekeyboards/qmk_firmware.git
git fetch upstream
git merge upstream/master
```

### Keyboard layout by the-frey

This is a layout that allows access to all the paren keys easily, has a tab on the lower layer (for SUPER-TAB app switching) and some utility features like PGUP/PGDOWN and HOME/END.

In addition, the arrows are on the lower layer and are bound to the vim keys (h,j,k,l). I've found this a productive layout for programming in emacs and hopefully you will too. 

The layout image above shows the keymap, with each key marked with all three layers:

- The top indicates the raise layer
- The middle indicates the default layer
- The bottom indicates the lower layer

All the keys respond as you'd expect to the 'shift' key - i.e. on a UK/GB keyboard, `/` becomes `?` and so on.

