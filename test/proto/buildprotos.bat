for /R %%i in (*.proto) do (
    %PROTOC% %PROTOC_FLAGS% --proto_path=%cd% --proto_path=%ENVOY_DEPENDENCY_ROOT%\googleapis --cpp_out=%cd% "%%i"
)

mkdir debug
cl /nologo /c /EHsc /I %PROTOC_OUTPUT%\googleapis /D_DEBUG %cd%\bookstore.pb.cc /Fo:%cd%\debug\bookstore.pb.obj
lib /nologo /out:%cd%\debug\bookstore.lib %cd%\debug\bookstore.pb.obj

cl /nologo /c /EHsc /I %PROTOC_OUTPUT%\googleapis /D_DEBUG %cd%\helloworld.pb.cc /Fo:%cd%\debug\helloworld.pb.obj
lib /nologo /out:%cd%\debug\helloworld.lib %cd%\debug\helloworld.pb.obj

mkdir release

cl /nologo /c /EHsc /I %PROTOC_OUTPUT%\googleapis /DNDEBUG /Osx %cd%\bookstore.pb.cc /Fo:%cd%\release\bookstore.pb.obj
lib /nologo /out:%cd%\release\bookstore.lib %cd%\release\bookstore.pb.obj

cl /nologo /c /EHsc /I %PROTOC_OUTPUT%\googleapis /DNDEBUG /Osx %cd%\helloworld.pb.cc /Fo:%cd%\release\helloworld.pb.obj
lib /nologo /out:%cd%\release\helloworld.lib %cd%\release\helloworld.pb.obj