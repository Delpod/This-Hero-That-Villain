##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=LD30
ConfigurationName      :=Debug
WorkspacePath          := "C:\Projects\LD30"
ProjectPath            := "C:\Projects\LD30"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=xvix
Date                   :=08/23/14
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:\MinGW-4.8.1\bin\g++.exe 
SharedObjectLinkerName :=C:\MinGW-4.8.1\bin\g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="LD30.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\MinGW-4.8.1\bin\windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/SFML-2.0/include $(IncludeSwitch)C:/Box2D/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio-s-d $(LibrarySwitch)sfml-graphics-s-d $(LibrarySwitch)sfml-window-s-d $(LibrarySwitch)sfml-system-s-d $(LibrarySwitch)sfml-main-d $(LibrarySwitch)Box2D 
ArLibs                 :=  "libsfml-audio-s-d.a" "libsfml-graphics-s-d.a" "libsfml-window-s-d.a" "libsfml-system-s-d.a" "libsfml-main-d.a" "libBox2D.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/SFML-2.0/lib $(LibraryPathSwitch)C:/Box2D/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\MinGW-4.8.1\bin\ar.exe rcu
CXX      := C:\MinGW-4.8.1\bin\g++.exe 
CC       := C:\MinGW-4.8.1\bin\gcc.exe 
CXXFLAGS :=  -g -O0 -Wall -std=gnu++0x  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:\MinGW-4.8.1\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix): src/Game.cpp $(IntermediateDirectory)/src_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Game.cpp$(DependSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Game.cpp$(DependSuffix) -MM "src/Game.cpp"

$(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix) "src/Game.cpp"

$(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix): src/GameObject.cpp $(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix): src/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix) -MM "src/GameObject.cpp"

$(IntermediateDirectory)/src_GameObject.cpp$(PreprocessSuffix): src/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GameObject.cpp$(PreprocessSuffix) "src/GameObject.cpp"

$(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix): src/TextureManager.cpp $(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/TextureManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix): src/TextureManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix) -MM "src/TextureManager.cpp"

$(IntermediateDirectory)/src_TextureManager.cpp$(PreprocessSuffix): src/TextureManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_TextureManager.cpp$(PreprocessSuffix) "src/TextureManager.cpp"

$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix): src/Level.cpp $(IntermediateDirectory)/src_Level.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/Level.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Level.cpp$(DependSuffix): src/Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Level.cpp$(DependSuffix) -MM "src/Level.cpp"

$(IntermediateDirectory)/src_Level.cpp$(PreprocessSuffix): src/Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Level.cpp$(PreprocessSuffix) "src/Level.cpp"

$(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix): src/Player.cpp $(IntermediateDirectory)/src_Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Player.cpp$(DependSuffix): src/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Player.cpp$(DependSuffix) -MM "src/Player.cpp"

$(IntermediateDirectory)/src_Player.cpp$(PreprocessSuffix): src/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Player.cpp$(PreprocessSuffix) "src/Player.cpp"

$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix): src/Enemy.cpp $(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix): src/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix) -MM "src/Enemy.cpp"

$(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix): src/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix) "src/Enemy.cpp"

$(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix): src/MenuButton.cpp $(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/LD30/src/MenuButton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix): src/MenuButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix) -MM "src/MenuButton.cpp"

$(IntermediateDirectory)/src_MenuButton.cpp$(PreprocessSuffix): src/MenuButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MenuButton.cpp$(PreprocessSuffix) "src/MenuButton.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Game.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_GameObject.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_GameObject.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_GameObject.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_TextureManager.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_TextureManager.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_TextureManager.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Level.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Level.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Level.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Player.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Player.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Player.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_MenuButton.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_MenuButton.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_MenuButton.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/LD30"


