INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
	)

SET(DICT_FILE RootHelperUtilsDict.cxx)

ROOT_GENERATE_DICTIONARY(
	"PlotHelper.h;ProtoEvent.h;ValErrPair.h"
	${CMAKE_CURRENT_SOURCE_DIR}/LinkDef.h
	${DICT_FILE}
	"${CMAKE_CURRENT_SOURCE_DIR}"
	)

ADD_LIBRARY(
	root-helper-utils
	STATIC
	PlotHelper.cxx
	ProtoEvent.cxx
	ValErrPair.cxx
	${DICT_FILE}
	utils.cc
	)

TARGET_LINK_LIBRARIES(
	root-helper-utils
	${ROOT_LIBRARIES}
	)
