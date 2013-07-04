COCOS2DX_PATH = /home/igor/Development/cocos2d-x-2.1.4/cocos2dx
COCOS_PATH = /home/igor/Development/cocos2d-x-2.1.4

EXECUTABLE = FruitNinja

INCLUDES =  -I../ \
			-I../Classes \
			-I../Classes/Screens \
			-I../Classes/Enemies \
			-I../Classes/Managers \
			-I../Classes/Entities \
			-I../Classes/Utils \
			-I../Classes/Graphics \
			-I../Classes/TEST \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/platform/third_party/linux \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform \
			-I$(COCOS2DX_PATH)/platform/linux \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS_PATH)/extensions/ \
			-I$(COCOS_PATH)/external/ \
			-I$(COCOS_PATH)/CocosDenshion/include

SOURCES = ./main.cpp \
			../Classes/Options.cpp \
			../Classes/AppDelegate.cpp \
			../Classes/Processor.cpp \
			../Classes/Utils/Utils.cpp \
			../Classes/Utils/Touchable.cpp \
			../Classes/Entities/Entity.cpp \
			../Classes/Entities/ImpulseEntity.cpp \
			../Classes/Entities/Fruit.cpp \
			../Classes/Entities/Part.cpp \
			../Classes/Entities/Label.cpp \
			../Classes/Entities/Splash.cpp \
			../Classes/Entities/Particles.cpp \
			../Classes/Entities/Drop.cpp \
			../Classes/Entities/Cutter.cpp \
			../Classes/Entities/Heart.cpp \
			../Classes/Entities/Spark.cpp \
			../Classes/Entities/Wave.cpp \
			../Classes/Entities/Mark.cpp \
			../Classes/Managers/EntityManager.cpp \
			../Classes/Managers/BatchEntityManager.cpp \
			../Classes/Screens/Screen.cpp \
			../Classes/Screens/Menu.cpp \
			../Classes/Managers/ScreenManager.cpp \
			../Classes/Managers/DropsManager.cpp \
			../Classes/Graphics/Texture.cpp \
			../Classes/TEST/TouchTrailLayer.cpp \
			../Classes/TEST/CCBlade.cpp \

COCOS_ROOT = ../../../..
include $(COCOS2DX_PATH)/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d -lcocosdenshion
COCOS_LIBS = $(LIB_DIR)/libcocos2d.so \
			 $(LIB_DIR)/libcocosdenshion.so

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@
