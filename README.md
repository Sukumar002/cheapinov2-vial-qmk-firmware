# cheapinov2-vial-qmk-firmware
Firmware files for the cheapino built against the latest vial-qmk version (as of 8/6/2026 at time of first commit)


cheapino_vial-encoder-enabled.uf2: the firmware file itself to be flashed to the cheapinov2 controller. This is built defaulting to the default keymap from the original cheapino repository, with 14 dynamic layers and built using the top pinky keys on both half as the vial unlock keys. this version has working encoders.

cheapino-dvorak-qwerty-brm.vil: my vial config save based on a dvorak base layer, a toggle-able qwerty layer, nav, num/symbol, function/media and mouse layer. There are many macros and combos that are tailored to my workflow, many of which are focused on navigating tmux in the terminal. Included in case anyone finds it interesting or useful. This is to be used with the firmware that has working encoders.

cheapino directory: the source code for compilation of this firmware. To successfully compile, you must place it in the vial-qmk/keyboards directory of your vial-qmk source tree once you have cloned it from the vial project's git repository.

cheapino_vial-no-encoder.uf2: old version of the firmware created before I got the encoders working.

dvorak-qwerty-brm-bleys43-no-encoder.vil: my old keymap save that is used with the old firmware without working encoders.


## Sukumar's Cheapino Vial keymap

Import the separately supplied `CheapinoV2.vil` file as the Vial layout reference for the 14-layer layout and six configured combos. Import it in Vial after flashing the matching Vial-enabled firmware. The firmware exposes 14 dynamic layers and evaluates combos from layer 0, so the same six combos remain available while any other layer is active.

Firmware source: `cheapino/keymaps/vial/`. The Vial keyboard definition and unlock configuration remain in that directory.
