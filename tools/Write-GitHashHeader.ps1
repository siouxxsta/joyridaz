
param(
    [Parameter(Mandatory)]
    [string]$OutputFile
)

$repoRoot = Split-Path -Parent $PSScriptRoot

$sha1 = ""
if (Get-Command git -ErrorAction SilentlyContinue) {
    $sha1 = git -C $repoRoot rev-parse --short HEAD 2>$null
}

@"
#define GIT_SHA1 "$sha1"
const char* g_GIT_SHA1 = GIT_SHA1;
"@ | Set-Content -Path $OutputFile -Encoding utf8