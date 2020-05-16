This package provides a simple interface to run google perftools in R.

The package requires `libgoogle-perftools-dev` and `google-perftools` packages to be installed:

On Debian/Ubuntu run:
```bash
sudo apt isntall google-perftools libgoogle-perftools-dev
```

Install the package:
```r
devtools::install_github("assaron/rgperftools")
```

Loading package:


```r
library(rgprofiler)
```

We'll be profiling `fgsea`:


```r
library(fgsea)
data(exampleRanks)
data(examplePathways)
```

Running `fgsea` wrapped in profiler:



```r
profOut <- tempfile("prof")
start_profiler(profOut)
fr <- fgseaMultilevel(examplePathways, exampleRanks, eps=0)
stop_profiler()
```


To get the visualization of results we first need path to used `fgsea.so`:


```r
fgseaSoPath <- getLoadedDLLs()[["fgsea"]][["path"]]
fgseaSoPath
```

```
## [1] "/home/alserg/R/x86_64-pc-linux-gnu-library/3.6/fgsea/libs/fgsea.so"
```

And now we can explore the profiler output with `google-pprof`:


```r
profOutSvg <- paste0(profOut, ".gif")
system2("google-pprof", args=c("--gif", fgseaSoPath, profOut), 
        stdout=profOutSvg)
```

Here the result:

![](https://raw.githubusercontent.com/assaron/rgperftools/master/vignettes/images/prof.svg)


