void fecharJanela() {
	HWND hWnd = GetConsoleWindow();
    if (hWnd != NULL) {
        PostMessage(hWnd, WM_CLOSE, 0, 0);
    }
}

void comandoExit() {
	fecharJanela();	
}

