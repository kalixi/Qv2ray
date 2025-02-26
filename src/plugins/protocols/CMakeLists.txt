set(PROTOCOL_PLUGIN_TARGET QvPlugin-BuiltinProtocolSupport)

macro(ADD_SOURCE mode name)
    list(APPEND PLUGIN_UI_SOURCE "${CMAKE_CURRENT_LIST_DIR}/ui/${mode}/${name}.ui")
    list(APPEND PLUGIN_UI_SOURCE "${CMAKE_CURRENT_LIST_DIR}/ui/${mode}/${name}.cpp")
    list(APPEND PLUGIN_UI_SOURCE "${CMAKE_CURRENT_LIST_DIR}/ui/${mode}/${name}.hpp")
endmacro()

ADD_SOURCE(outbound blackhole)
ADD_SOURCE(outbound dns)
ADD_SOURCE(outbound freedom)
ADD_SOURCE(outbound httpout)
ADD_SOURCE(outbound socksout)
ADD_SOURCE(outbound shadowsocks)
ADD_SOURCE(outbound vmess)
ADD_SOURCE(outbound loopback)
ADD_SOURCE(outbound trojan)

ADD_SOURCE(inbound dokodemo-door)
ADD_SOURCE(inbound httpin)
ADD_SOURCE(inbound socksin)
#ADD_SOURCE(inbound shadowsocks)
#ADD_SOURCE(inbound vless)
#ADD_SOURCE(inbound vmess)

qv2ray_add_plugin(${PROTOCOL_PLUGIN_TARGET} Widgets
    INSTALL_PREFIX_MACOS "${CMAKE_INSTALL_PREFIX}/qv2ray.app/Contents/Resources/plugins"
    CLASS_NAME "InternalProtocolSupportPlugin")

target_sources(${PROTOCOL_PLUGIN_TARGET} PRIVATE
    ${PLUGIN_UI_SOURCE}
    ${CMAKE_CURRENT_LIST_DIR}/resx.qrc
    ${CMAKE_CURRENT_LIST_DIR}/BuiltinProtocolPlugin.hpp
    ${CMAKE_CURRENT_LIST_DIR}/BuiltinProtocolPlugin.cpp
    ${CMAKE_CURRENT_LIST_DIR}/core/OutboundHandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/core/OutboundHandler.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/Interface.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/PluginSettingsWidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/PluginSettingsWidget.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/PluginSettingsWidget.ui
    )

target_include_directories(${PROTOCOL_PLUGIN_TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../PluginsCommon)
