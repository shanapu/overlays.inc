[INC] Overlays

[![Build Status](https://img.shields.io/travis/shanapu/overlays.inc/master.svg?style=flat-square)](https://travis-ci.org/shanapu/overlays.inc?branch=master)

there are three stock functions and a timer:

##### Precache & prepare download for overlays & decals
```stock void PrecacheDecalAnyDownload(char[] sOverlay);```

##### Show overlay to a client with lifetime | 0.0 = no auto remove
```stock void ShowOverlay(int client, char[] path, float lifetime);```

##### Show overlay to all clients with lifetime | 0.0 = no auto remove
```stock void ShowOverlayAll(char[] path, float lifetime);```

##### Timer! - Remove overlay from a client - Timer!
```stock Action DeleteOverlay(Handle timer, any client);```

## For more info & comments take a look at [overlays_plugin_example.sp](https://github.com/shanapu/overlays.inc/blob/master/addons/sourcemod/scripting/overlays_plugin_example.sp)
