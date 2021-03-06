#include "include/cef_app.h"
#include "includes/cef_handler.h"
#include "includes/cef_base_win.h"
#include "includes/util.h"

extern CefRefPtr<ClientHandler> g_handler;

namespace appjs {

void CefBase::Init(){}

void CefBase::AddWebView(CefWindowHandle parent, RECT windowRect, char* url, Settings* settings) {
  CefWindowInfo windowInfo;
  windowInfo.SetAsChild(parent, windowRect);
  windowInfo.SetTransparentPainting(true);
  g_handler->browserSettings_.web_security_disabled = settings->getBoolean("disableSecurity", false);
  CefBrowser::CreateBrowser(windowInfo, static_cast<CefRefPtr<CefClient>>(g_handler), url, g_handler->browserSettings_);
}

} /* appjs */
