#!/usr/bin/env pwsh
# Generates Visual Studio solution files using premake5

param(
    [string]$VSVersion = "vs2026"
)

$premake = Join-Path $PSScriptRoot "premake.exe"

if (-not (Test-Path $premake)) {
    Write-Error "premake.exe not found at $premake"
    exit 1
}

& $premake $VSVersion --file="../premake.lua" @args