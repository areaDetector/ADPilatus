ADPilatus Releases
==================

The latest untagged master branch can be obtained at
https://github.com/areaDetector/ADPilatus.

Tagged source code and pre-built binary releases prior to R2-0 are included
in the areaDetector releases available via links at
https://cars.uchicago.edu/software/epics/areaDetector.html.

Tagged source code releases from R2-0 onward can be obtained at 
https://github.com/areaDetector/ADPilatus/releases.

Tagged prebuilt binaries from R2-0 onward can be obtained at
https://cars.uchicago.edu/software/pub/ADPilatus.

The versions of EPICS base, asyn, and other synApps modules used for each release can be obtained from 
the EXAMPLE_RELEASE_PATHS.local, EXAMPLE_RELEASE_LIBS.local, and EXAMPLE_RELEASE_PRODS.local
files respectively, in the configure/ directory of the appropriate release of the 
[top-level areaDetector](https://github.com/areaDetector/areaDetector) repository.


Release Notes
=============
R2-9 (24-February-2020)
---
* Fixed driver to move array counter increment to before setting NDArray UniqueId.
* Changed documentation to .rst files on areaDetector.github.io.
* Added .bob files for Phoebus Display Manager

R2-8 (9-January-2020)
---
* Fixed a serious bug in the readTiff function that could cause the driver to
  time out reading a TIFF file.
  It was using NDArray::dataSize as the expected size of the TIFF file.
  This is incorrect, dataSize can be larger than the expected size.
  Changed to call NDArray::getInfo() to determine the expected size of the file.
* Added temperature/humidity channel 3.  Some detectors use channel 3.
* Moved cbfSrc from this repository to ADSupport/supportApp/cbfSrc.
  This allows the new ADMMPAD repository to use the code as well.

R2-7 (4-December-2018)
---
* Fixed problem with stopping an acquisition.  Previously the driver was sending the commands
  "Stop" and "K", because these were the required commands for an old version of camserver.
  New versions of camserver no longer support the "Stop" command, and the "K" command only
  stops an acquisition series, not the current acquisition.  Replaced the "Stop" command with
  "camcmd k" which also stops the current acquisition.
* Increased the timeout for response on a camserver power reset command.
* Removed obsolete display files in op/ui, op/opi, op/edl.
  The correct versions are in the autoconvert subdirectories.

R2-6 (2-July-2018)
---
* Added support for new PVs in ADCore R3-3 in opi files (NumQueuedArrays, etc.)
* Added ADBuffers.adl to main medm screen.
* Changed configure/RELEASE files for compatibility with areaDetector R3-3.
* Improved op/*/autoconvert/* files with better medm files and better converters.


R2-5 (28-January-2018)
---
* Added support for the ResetModulePower command in camserver 7.9.0 and higher.
  This is important for CdTe detectors where the high-voltage needs to be cycled from
  time to time, particularly after strong saturation of pixels.
* Fixed the parsing of the camserver "Version" command for new versions of camserver
  where it no longer contains the string "tvx-".
* Fixed the parsing of the camserver "Thread" command to read the temperature and
  relative humdidity.  Recent camserver versions do not always return "Channel 0:", 
  and this prevented it from working correctly.
* Fixed medm adl files to improve the autoconversion to other display manager files.
* Added op/Makefile to automatically convert adl files to edl, ui, and opi files.
* Updated the edl, ui, and opi autoconvert directories to contain the conversions
  from the most recent adl files.


R2-4 (04-July-2017)
---
* Only increment NDArrayCounter if the driver got an image.
  When acquiring with `ADNumImages` > 1, `NDArrayCounter`  was immediately incremented before the driver 
  confirmed that it actually got an image.


R2-3 (20-February-2017)
----
* Added new record Energy.  This is used to tell camserver the actual x-ray energy being used,
  which is important for proper flat-field corrections.  Previously it was assumed that camserver
  was setting the energy to 2 * ThresholdEnergy. There are 2 problems with this
  - Sometimes it is desireable to set the threshold to a value which is different from Energy/2.
  - camserver is always supposed to set the energy to 2 * EnergyThreshold if the energy is not 
    specified.  However, some versions of camserver have a bug and they do not do this unless the
    energy has been explicitly set at least once.  The driver now always sends the energy value to
    camserver.  If the Energy record is set to 0 then the driver will send the 2 * ThresholdEnergy
    to camserver for the energy.
* If camserver is saving TIFF files then the driver now reads the TIFFImageDescription tag from the
  TIFF file.  This is a long string that camserver writes to the file containing all of the detector
  settings, including threshold, energy, etc.  The driver adds this information to the NDArray using
  an NDAttribute called TIFFImageDescription.  The NDFileTIFF plugin in ADCore R2-6 was changed to
  write this complete attribute to the TIFFImageDescription tag in the new TIFF file.  
  It will also be written by the NDFileNetCDF, NDFileHDF5, and NDFileNexus plugins.  However these 
  plugins are currently limited to 256 character string attributes, so some of the information will
  be lost because the string is longer than 256 characters.
* Added PhiIncr, ChiIncr, Omega and OmegaIncr to pilatusAncillary.adl medm screen and pilatus_settings.req.

R2-2 (13-September-2015)
----
* Fix to allow exposure times less than 1e-6 seconds.
* Add new records: PhiIncr, ChiIncr, Omega and OmegaIncr
  which are suppported in camserver version: tvx-7.3.13-121212b
* Added Dectris user manuals to documentation directory


R2-1 (16-April-2015)
----
* Changes for compatibility with ADCore R2-2.


R2-0 (4-April-2014)
----
* Moved the repository to [Github](https://github.com/areaDetector/ADPilatus).
* Re-organized the directory structure to separate the driver library from the example IOC application.
* Increased timeout when setting threshold from 90 to 110 seconds. 
  Needed on 6M with new camserver. Thanks to Lewis Muir.
* Changed the code that reads the temperature and humidiy from running in a separate thread in the driver
  to being called via the standard ReadStatus record from ADBase.template.

R1-9-1 and earlier
------------------
Release notes are part of the
[areaDetector Release Notes](https://cars.uchicago.edu/software/epics/areaDetectorReleaseNotes.html).

