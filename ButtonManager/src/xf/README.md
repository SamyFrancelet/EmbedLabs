# The XF Project
XF project used by other projects as _git submodule_.

> Note 
> 
> This is not the original XF project!

## Introduction 

This is more of a 'git fork' of the orignial project located in the 
[XF laboratory project](https://gitlab.hevs.ch/course/ptr/lab/xf/tree/master/01-work/src/xf).

The XF is used by following projects as _git submodule_:
- [ButtonManager Project](https://gitlab.hevs.ch/course/ptr/lab/buttonmanager/tree/develop/01-work/ButtonManager/src)
- [RealtimeOscilloscope Project](https://gitlab.hevs.ch/course/ptr/lab/realtime-oscilloscope/tree/develop/01-work/RealtimeOscilloscope/src)

> Note
>
> The XF project should never be hand out to the students, because it contains
> already the solution for the XF laboratory!
>
> For the XF laboratory, provide the [work.zip](https://gitlab.hevs.ch/course/ptr/lab/xf/tree/master/03-release)
> to the students instead.

## Update XF Project to latest XF Release
- Checkout _develop_ branch
- Remove file `xf-core.pri`
- Remove all folders (config, core, etc.)
- Keep files `README.md` and `.git` files
- Checkout _master_ branch from [XF laboratory project](https://gitlab.hevs.ch/course/ptr/lab/xf/tree/master/01-work/src/xf)
- Copy paste the code into this project
- Commit changes
- Make a release with the same tag given in the _XF laboratory project_
