INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${ROOT_INCLUDE_DIR}
	)

SET(DICT_FILE RootHelperUtilsDict.cxx)

ROOT_GENERATE_DICTIONARY(
	"H1F.h;H1I.h;H1D.h;H2F.h;H2I.h;H2D.h;PlotHelper.h;MultiGraph.h;ProtoEvent.h;ValErrPair.h"
	${CMAKE_CURRENT_SOURCE_DIR}/LinkDef.h
	${DICT_FILE}
	"${CMAKE_CURRENT_SOURCE_DIR}"
	)

SET(
	SOURCES
	H1I.cxx
	H1F.cxx
	H1D.cxx
	H2I.cxx
	H2F.cxx
	H2D.cxx
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

IF(FORCE_32BIT)
        SET_TARGET_PROPERTIES(root-helper-utils PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
        SET_TARGET_PROPERTIES(root-helper-utils-shared PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
ENDIF()
