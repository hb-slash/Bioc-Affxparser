%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Do not modify this file since it was automatically generated from:
% 
%  
% 
% on Wed Mar 29 20:22:51 2006.
% 
% Generator was the Rdoc class, which is part of the R.oo package written
% by Henrik Bengtsson, 2001-2006.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\name{findCdf}
\alias{findCdf}


\title{Search for CDF files in multiple directories}

\description{
 Search for CDF files in multiple directories.
}

\usage{findCdf(chipType=NULL, paths=NULL, pattern="[.](c|C)(d|D)(f|F)$", ...)}

\arguments{
 \item{chipType}{A \code{\link[base]{character}} string of the chip type to search for.}
 \item{paths}{A \code{\link[base]{character}} \code{\link[base]{vector}} of paths to be searched.
   The current directory is always searched at the beginning.
   If \code{\link[base]{NULL}}, default paths are searched.  For more details, see below.}
 \item{pattern}{A regular expression file name pattern to match.}
 \item{...}{Additional arguments passed to \code{\link{findFiles}}().}
}

\value{
 Returns a \code{\link[base]{vector}} of the full pathnames of the files found.
}

\details{
  Note, the current directory is always searched at the beginning.
  This provides an easy way to override other files in the search path.
  If \code{paths} is \code{\link[base]{NULL}}, then a set of default paths are searched.
  The default search path is consituted of:
  \enumerate{
   \item \code{"."}
   \item \code{getOption("AFFX_CDF_PATH")}
   \item \code{Sys.getenv("AFFX_CDF_PATH")}
   \item \code{"cdf/;data/cdf/"}
  }

  One of the easiest ways to set system variables for \R is to
  set them in an \code{.Renviron} file, see \code{\link[base]{Startup}}
  for more details.
}

\examples{

# Find a specific CDF file
cdfFile <- findCdf("Mapping50K_Xba240")
print(cdfFile)

# Find all CDF files in search path
cdfFiles <- findCdf(firstOnly=FALSE)
print(cdfFiles)

# Find the first CDF file (no matter what it is)
cdfFile <- findCdf()
print(cdfFile)

}

\seealso{
  This method is used internally by \code{\link{readCelUnits}}() if the CDF
  file is not specified.
}

\author{Henrik Bengtsson (\url{http://www.braju.com/R/})}



\keyword{file}
\keyword{IO}