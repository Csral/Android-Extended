# Parser
The files syntax for the parser programs is as follows:

config.mdlr
main(index/any name).mdlr
your files

# Config

Config files may have many variables for developers help, but these are manditory,

### Type
apply type {type}
we'll see about apply later but simply say it is for defining env variables.

{type} can be one of following: plugin, module, *
plugin gets installed as a plugin to the moduler binary as a custom opt
module enables users to parse file to install module (as specified by parser)
* means both.

### Module opts
if your type is module or has module flag, a module.prop would be required as in magisk.
Along them one has to mention the following:

boot_module (1|0) -> Is this module not having any files/module but a script to run on boot.
boot_time (1|0) -> Boot script to be run at post fs or service.d [0 for service.d and other for postfs]
for boot_time, one has to set boot_module as true.
patch_bootimg (1|0|-1)-> Patch boot.img; 1 = true, 0 = false, -1 = managed by parser/module files.
