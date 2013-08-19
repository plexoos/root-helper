INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
	)

ROOT_GENERATE_DICTIONARY(
	"PlotHelper.h;ProtoEvent.h;ValErrPair.h"
	${CMAKE_CURRENT_SOURCE_DIR}/LinkDef.h
	Dict.cxx
	"${CMAKE_CURRENT_SOURCE_DIR}"
	)

ADD_LIBRARY(
	root-helper-utils
	SHARED
	PlotHelper.cxx
	ProtoEvent.cxx
	ValErrPair.cxx
	Dict.cxx
	utils.cc
	)

TARGET_LINK_LIBRARIES(
	root-helper-utils
	${ROOT_LIBRARIES}
	)
