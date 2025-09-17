# tabbed - generic tabbed interface

tabbed is a simple tabbed X window container.

## Requirements

In order to build tabbed you need the Xlib header files.

## Installation

If you use nix than just use it as any other flake.
Otherwise use standard

```
make clean install
```

## Running tabbed

See the man page for details.

## Applied patches

Sources are in `patches` directory.

### In original form

- keyrelease
- xresources

### Modified

- hidetabs (fixed to match new version of tabbed)
- bar-height (fixed to play along with others)
