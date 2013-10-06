INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
	)

SET(DICT_FILE RootHelperUtilsDict.cxx)

ROOT_GENERATE_DICTIONARY(
	"H2I.h;PlotHelper.h;MultiGraph.h;ProtoEvent.h;ValErrPair.h"
	${CMAKE_CURRENT_SOURCE_DIR}/LinkDef.h
	${DICT_FILE}
	"${CMAKE_CURRENT_SOURCE_DIR}"
	)

SET(
	SOURCES
	H2I.cxx
	PlotHelper.cxx
	MultiGraph.cxx
	ProtoEvent.cxx
	ValErrPair.cxx
	${DICT_FILE}
	utils.cc
	)

ADD_LIBRARY(
	root-helper-utils
	STATIC
	${SOURCES}
	)

ADD_LIBRARY(
	root-helper-utils-shared
	SHARED
	${SOURCES}
	)

TARGET_LINK_LIBRARIES(
	root-helper-utils
	${ROOT_LIBRARIES}
	)

TARGET_LINK_LIBRARIES(
	root-helper-utils-shared
	${ROOT_LIBRARIES}
	)
