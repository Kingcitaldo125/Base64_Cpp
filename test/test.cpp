#include <gtest/gtest.h>

#include "base64.cpp"

// ----------------
// -              -
// -    Encode    -
// -              -
// ----------------

TEST(Encode, SimpleTestOne) {
  EXPECT_EQ(base64encode("Many hands make light work."),
            "TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu");
}

TEST(Encode, SimpleTestTwo) {
  EXPECT_EQ(base64encode(
                "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxy0123456789"),
            "QUJDREVGR0hJSktMTU5PUFFSU1RVVldYWWFiY2RlZmdoaWprbG1ub3BxcnN0dXZ3eH"
            "kwMTIzNDU2Nzg5");
}

TEST(Encode, SimpleTestThree) { EXPECT_EQ(base64encode("."), "Lg=="); }

TEST(Encode, SimpleTestFour) { EXPECT_EQ(base64encode(".."), "Li4="); }

TEST(Encode, SimpleTestFive) { EXPECT_EQ(base64encode("..."), "Li4u"); }

TEST(Encode, SimpleTestSix) { EXPECT_EQ(base64encode("...."), "Li4uLg=="); }

TEST(Encode, BigTest) {
  EXPECT_EQ(
      base64encode(
          "PKIcrxsTOB1gGk0UiokDq8cDKeE9jPLpfngDTgi66iumwK0cmPOKhfUrl4241rPBl7Sv"
          "wIRlP6XkHYJWPvd3eYyrK1GOj7bpunMqY1lOLYf9HjDO8oYFqxNX9EWwvedeaCeA6vD0"
          "AwOBuggNEpMK3BwqXkigQykDlfmkO527CpRtQy5tjqCbNLAPiscAiKwfqOGuyds63DWE"
          "sSIMHNrYQKgLjUL65iY6Yleut74tX3xvtuYalPjtbgmJpVa6O4chKHXPvUbbcS9Vskff"
          "f1x9jfoAjYq1PKA4LTBJK2AHBtC2c9RR6BOykCNtjcUDys2KASDYT8Gd3A51mBMcEksG"
          "regt6YqAwYoj9R75cPbq6yeXyiViq7Lo54sSvYrNxl41a2JeCAJbr3UGqDlm3mR8RcyC"
          "PUXPVbxq0oJRdPrJkYCWeCnPdcKxxPquiex46EDC0FUDHLo5I6Uervt35DrkyhxX8tvX"
          "9HSw66N5ibqomnf8CHfyjMs49uKMur3kPeEaOys8P4kDtOklF4jvph04Vx9nu1fsu8Ou"
          "nNONtguGv7QmF1fMHjC7RCpLvQeVVsT3cVkL7mrcYFkgG6qWQc2H7qB55F4YYIR4ecoD"
          "3NOL9dpKQIUoVVooF3hE3qNn8HJQPcksAYaniJmdtOREIoMbRieLiibNkHaLYuJn3QUo"
          "Y6utkmrgayc6fRaxkQbltrrr4BI6W05xFFIvIb6cWJra6n85jXjVLxfKaux1t1qxeR4Y"
          "YX5n3sxIjGiBi3JvmtCHPfojGh9AYoHduGhiXAF6gbshaSrtFRVim9bhFRFnI6jmRMmw"
          "3o8LBNV3nWB1g7q3qQqfmSHAarrbq69ju6tRpggGdTMAiNitBjeId8OXktQWgx2aLQa9"
          "O7yDB4trQssCkfWirrVuLB0hYNkIfb9YnW33ULNuM4qdttpfeEExBd8C4A0PDwSg0Gf3"
          "NocvBXrTdYFiBMGNX67VpTCAbBVlTkXAq9n8bsa3bNb9MipI"),
      "UEtJY3J4c1RPQjFnR2swVWlva0RxOGNES2VFOWpQTHBmbmdEVGdpNjZpdW13SzBjbVBPS2hm"
      "VXJsNDI0MXJQQmw3U3Z3SVJsUDZYa0hZSldQdmQzZVl5cksxR09qN2JwdW5NcVkxbE9MWWY5"
      "SGpETzhvWUZxeE5YOUVXd3ZlZGVhQ2VBNnZEMEF3T0J1Z2dORXBNSzNCd3FYa2lnUXlrRGxm"
      "bWtPNTI3Q3BSdFF5NXRqcUNiTkxBUGlzY0FpS3dmcU9HdXlkczYzRFdFc1NJTUhOcllRS2dM"
      "alVMNjVpWTZZbGV1dDc0dFgzeHZ0dVlhbFBqdGJnbUpwVmE2TzRjaEtIWFB2VWJiY1M5VnNr"
      "ZmZmMXg5amZvQWpZcTFQS0E0TFRCSksyQUhCdEMyYzlSUjZCT3lrQ050amNVRHlzMktBU0RZ"
      "VDhHZDNBNTFtQk1jRWtzR3JlZ3Q2WXFBd1lvajlSNzVjUGJxNnllWHlpVmlxN0xvNTRzU3ZZ"
      "ck54bDQxYTJKZUNBSmJyM1VHcURsbTNtUjhSY3lDUFVYUFZieHEwb0pSZFBySmtZQ1dlQ25Q"
      "ZGNLeHhQcXVpZXg0NkVEQzBGVURITG81STZVZXJ2dDM1RHJreWh4WDh0dlg5SFN3NjZONWli"
      "cW9tbmY4Q0hmeWpNczQ5dUtNdXIza1BlRWFPeXM4UDRrRHRPa2xGNGp2cGgwNFZ4OW51MWZz"
      "dThPdW5OT050Z3VHdjdRbUYxZk1IakM3UkNwTHZRZVZWc1QzY1ZrTDdtcmNZRmtnRzZxV1Fj"
      "Mkg3cUI1NUY0WVlJUjRlY29EM05PTDlkcEtRSVVvVlZvb0YzaEUzcU5uOEhKUVBja3NBWWFu"
      "aUptZHRPUkVJb01iUmllTGlpYk5rSGFMWXVKbjNRVW9ZNnV0a21yZ2F5YzZmUmF4a1FibHRy"
      "cnI0Qkk2VzA1eEZGSXZJYjZjV0pyYTZuODVqWGpWTHhmS2F1eDF0MXF4ZVI0WVlYNW4zc3hJ"
      "akdpQmkzSnZtdENIUGZvakdoOUFZb0hkdUdoaVhBRjZnYnNoYVNydEZSVmltOWJoRlJGbkk2"
      "am1STW13M284TEJOVjNuV0IxZzdxM3FRcWZtU0hBYXJyYnE2OWp1NnRScGdnR2RUTUFpTml0"
      "QmplSWQ4T1hrdFFXZ3gyYUxRYTlPN3lEQjR0clFzc0NrZldpcnJWdUxCMGhZTmtJZmI5WW5X"
      "MzNVTE51TTRxZHR0cGZlRUV4QmQ4QzRBMFBEd1NnMEdmM05vY3ZCWHJUZFlGaUJNR05YNjdW"
      "cFRDQWJCVmxUa1hBcTluOGJzYTNiTmI5TWlwSQ==");
}

// ----------------
// -              -
// -    Decode    -
// -              -
// ----------------

TEST(Decode, SimpleTestOne) {
  EXPECT_EQ(base64decode("TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu"),
            "Many hands make light work.");
}

TEST(Decode, SimpleTestTwo) {
  EXPECT_EQ(base64decode("QUJDREVGR0hJSktMTU5PUFFSU1RVVldYWWFiY2RlZmdoaWprbG1ub"
                         "3BxcnN0dXZ3eHkwMTIzNDU2Nzg5"),
            "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxy0123456789");
}

TEST(Decode, SimpleTestThree) { EXPECT_EQ(base64decode("Lg=="), "."); }

TEST(Decode, SimpleTestFour) { EXPECT_EQ(base64decode("Li4="), ".."); }

TEST(Decode, SimpleTestFive) { EXPECT_EQ(base64decode("Li4u"), "..."); }

TEST(Decode, SimpleTestSix) { EXPECT_EQ(base64decode("Li4uLg=="), "...."); }

TEST(Decode, BigTest) {
  EXPECT_EQ(
      base64decode(
          "UEtJY3J4c1RPQjFnR2swVWlva0RxOGNES2VFOWpQTHBmbmdEVGdpNjZpdW13SzBjbVBP"
          "S2hmVXJsNDI0MXJQQmw3U3Z3SVJsUDZYa0hZSldQdmQzZVl5cksxR09qN2JwdW5NcVkx"
          "bE9MWWY5SGpETzhvWUZxeE5YOUVXd3ZlZGVhQ2VBNnZEMEF3T0J1Z2dORXBNSzNCd3FY"
          "a2lnUXlrRGxmbWtPNTI3Q3BSdFF5NXRqcUNiTkxBUGlzY0FpS3dmcU9HdXlkczYzRFdF"
          "c1NJTUhOcllRS2dMalVMNjVpWTZZbGV1dDc0dFgzeHZ0dVlhbFBqdGJnbUpwVmE2TzRj"
          "aEtIWFB2VWJiY1M5VnNrZmZmMXg5amZvQWpZcTFQS0E0TFRCSksyQUhCdEMyYzlSUjZC"
          "T3lrQ050amNVRHlzMktBU0RZVDhHZDNBNTFtQk1jRWtzR3JlZ3Q2WXFBd1lvajlSNzVj"
          "UGJxNnllWHlpVmlxN0xvNTRzU3ZZck54bDQxYTJKZUNBSmJyM1VHcURsbTNtUjhSY3lD"
          "UFVYUFZieHEwb0pSZFBySmtZQ1dlQ25QZGNLeHhQcXVpZXg0NkVEQzBGVURITG81STZV"
          "ZXJ2dDM1RHJreWh4WDh0dlg5SFN3NjZONWlicW9tbmY4Q0hmeWpNczQ5dUtNdXIza1Bl"
          "RWFPeXM4UDRrRHRPa2xGNGp2cGgwNFZ4OW51MWZzdThPdW5OT050Z3VHdjdRbUYxZk1I"
          "akM3UkNwTHZRZVZWc1QzY1ZrTDdtcmNZRmtnRzZxV1FjMkg3cUI1NUY0WVlJUjRlY29E"
          "M05PTDlkcEtRSVVvVlZvb0YzaEUzcU5uOEhKUVBja3NBWWFuaUptZHRPUkVJb01iUmll"
          "TGlpYk5rSGFMWXVKbjNRVW9ZNnV0a21yZ2F5YzZmUmF4a1FibHRycnI0Qkk2VzA1eEZG"
          "SXZJYjZjV0pyYTZuODVqWGpWTHhmS2F1eDF0MXF4ZVI0WVlYNW4zc3hJakdpQmkzSnZt"
          "dENIUGZvakdoOUFZb0hkdUdoaVhBRjZnYnNoYVNydEZSVmltOWJoRlJGbkk2am1STW13"
          "M284TEJOVjNuV0IxZzdxM3FRcWZtU0hBYXJyYnE2OWp1NnRScGdnR2RUTUFpTml0Qmpl"
          "SWQ4T1hrdFFXZ3gyYUxRYTlPN3lEQjR0clFzc0NrZldpcnJWdUxCMGhZTmtJZmI5WW5X"
          "MzNVTE51TTRxZHR0cGZlRUV4QmQ4QzRBMFBEd1NnMEdmM05vY3ZCWHJUZFlGaUJNR05Y"
          "NjdWcFRDQWJCVmxUa1hBcTluOGJzYTNiTmI5TWlwSQ=="),
      "PKIcrxsTOB1gGk0UiokDq8cDKeE9jPLpfngDTgi66iumwK0cmPOKhfUrl4241rPBl7SvwIRl"
      "P6XkHYJWPvd3eYyrK1GOj7bpunMqY1lOLYf9HjDO8oYFqxNX9EWwvedeaCeA6vD0AwOBuggN"
      "EpMK3BwqXkigQykDlfmkO527CpRtQy5tjqCbNLAPiscAiKwfqOGuyds63DWEsSIMHNrYQKgL"
      "jUL65iY6Yleut74tX3xvtuYalPjtbgmJpVa6O4chKHXPvUbbcS9Vskfff1x9jfoAjYq1PKA4"
      "LTBJK2AHBtC2c9RR6BOykCNtjcUDys2KASDYT8Gd3A51mBMcEksGregt6YqAwYoj9R75cPbq"
      "6yeXyiViq7Lo54sSvYrNxl41a2JeCAJbr3UGqDlm3mR8RcyCPUXPVbxq0oJRdPrJkYCWeCnP"
      "dcKxxPquiex46EDC0FUDHLo5I6Uervt35DrkyhxX8tvX9HSw66N5ibqomnf8CHfyjMs49uKM"
      "ur3kPeEaOys8P4kDtOklF4jvph04Vx9nu1fsu8OunNONtguGv7QmF1fMHjC7RCpLvQeVVsT3"
      "cVkL7mrcYFkgG6qWQc2H7qB55F4YYIR4ecoD3NOL9dpKQIUoVVooF3hE3qNn8HJQPcksAYan"
      "iJmdtOREIoMbRieLiibNkHaLYuJn3QUoY6utkmrgayc6fRaxkQbltrrr4BI6W05xFFIvIb6c"
      "WJra6n85jXjVLxfKaux1t1qxeR4YYX5n3sxIjGiBi3JvmtCHPfojGh9AYoHduGhiXAF6gbsh"
      "aSrtFRVim9bhFRFnI6jmRMmw3o8LBNV3nWB1g7q3qQqfmSHAarrbq69ju6tRpggGdTMAiNit"
      "BjeId8OXktQWgx2aLQa9O7yDB4trQssCkfWirrVuLB0hYNkIfb9YnW33ULNuM4qdttpfeEEx"
      "Bd8C4A0PDwSg0Gf3NocvBXrTdYFiBMGNX67VpTCAbBVlTkXAq9n8bsa3bNb9MipI");
}

// ----------------
// -              -
// - EncodeDecode -
// -              -
// ----------------

TEST(EncodeDecode, One) {
  EXPECT_EQ(base64decode(base64encode("Many hands make light work.")),
            "Many hands make light work.");
}

TEST(EncodeDecode, Two) {
  EXPECT_EQ(base64decode(base64encode("Man is distinguished.")),
            "Man is distinguished.");
}

TEST(EncodeDecode, Three) {
  EXPECT_EQ(
      base64decode(base64encode(
          "UEtJY3J4c1RPQjFnR2swVWlva0RxOGNES2VFOWpQTHBmbmdEVGdpNjZpdW13SzBjbVBP"
          "S2hmVXJsNDI0MXJQQmw3U3Z3SVJsUDZYa0hZSldQdmQzZVl5cksxR09qN2JwdW5NcVkx"
          "bE9MWWY5SGpETzhvWUZxeE5YOUVXd3ZlZGVhQ2VBNnZEMEF3T0J1Z2dORXBNSzNCd3FY"
          "a2lnUXlrRGxmbWtPNTI3Q3BSdFF5NXRqcUNiTkxBUGlzY0FpS3dmcU9HdXlkczYzRFdF"
          "c1NJTUhOcllRS2dMalVMNjVpWTZZbGV1dDc0dFgzeHZ0dVlhbFBqdGJnbUpwVmE2TzRj"
          "aEtIWFB2VWJiY1M5VnNrZmZmMXg5amZvQWpZcTFQS0E0TFRCSksyQUhCdEMyYzlSUjZC"
          "T3lrQ050amNVRHlzMktBU0RZVDhHZDNBNTFtQk1jRWtzR3JlZ3Q2WXFBd1lvajlSNzVj"
          "UGJxNnllWHlpVmlxN0xvNTRzU3ZZck54bDQxYTJKZUNBSmJyM1VHcURsbTNtUjhSY3lD"
          "UFVYUFZieHEwb0pSZFBySmtZQ1dlQ25QZGNLeHhQcXVpZXg0NkVEQzBGVURITG81STZV"
          "ZXJ2dDM1RHJreWh4WDh0dlg5SFN3NjZONWlicW9tbmY4Q0hmeWpNczQ5dUtNdXIza1Bl"
          "RWFPeXM4UDRrRHRPa2xGNGp2cGgwNFZ4OW51MWZzdThPdW5OT050Z3VHdjdRbUYxZk1I"
          "akM3UkNwTHZRZVZWc1QzY1ZrTDdtcmNZRmtnRzZxV1FjMkg3cUI1NUY0WVlJUjRlY29E"
          "M05PTDlkcEtRSVVvVlZvb0YzaEUzcU5uOEhKUVBja3NBWWFuaUptZHRPUkVJb01iUmll"
          "TGlpYk5rSGFMWXVKbjNRVW9ZNnV0a21yZ2F5YzZmUmF4a1FibHRycnI0Qkk2VzA1eEZG"
          "SXZJYjZjV0pyYTZuODVqWGpWTHhmS2F1eDF0MXF4ZVI0WVlYNW4zc3hJakdpQmkzSnZt"
          "dENIUGZvakdoOUFZb0hkdUdoaVhBRjZnYnNoYVNydEZSVmltOWJoRlJGbkk2am1STW13"
          "M284TEJOVjNuV0IxZzdxM3FRcWZtU0hBYXJyYnE2OWp1NnRScGdnR2RUTUFpTml0Qmpl"
          "SWQ4T1hrdFFXZ3gyYUxRYTlPN3lEQjR0clFzc0NrZldpcnJWdUxCMGhZTmtJZmI5WW5X"
          "MzNVTE51TTRxZHR0cGZlRUV4QmQ4QzRBMFBEd1NnMEdmM05vY3ZCWHJUZFlGaUJNR05Y"
          "NjdWcFRDQWJCVmxUa1hBcTluOGJzYTNiTmI5TWlwSQ==")),
      "UEtJY3J4c1RPQjFnR2swVWlva0RxOGNES2VFOWpQTHBmbmdEVGdpNjZpdW13SzBjbVBPS2hm"
      "VXJsNDI0MXJQQmw3U3Z3SVJsUDZYa0hZSldQdmQzZVl5cksxR09qN2JwdW5NcVkxbE9MWWY5"
      "SGpETzhvWUZxeE5YOUVXd3ZlZGVhQ2VBNnZEMEF3T0J1Z2dORXBNSzNCd3FYa2lnUXlrRGxm"
      "bWtPNTI3Q3BSdFF5NXRqcUNiTkxBUGlzY0FpS3dmcU9HdXlkczYzRFdFc1NJTUhOcllRS2dM"
      "alVMNjVpWTZZbGV1dDc0dFgzeHZ0dVlhbFBqdGJnbUpwVmE2TzRjaEtIWFB2VWJiY1M5VnNr"
      "ZmZmMXg5amZvQWpZcTFQS0E0TFRCSksyQUhCdEMyYzlSUjZCT3lrQ050amNVRHlzMktBU0RZ"
      "VDhHZDNBNTFtQk1jRWtzR3JlZ3Q2WXFBd1lvajlSNzVjUGJxNnllWHlpVmlxN0xvNTRzU3ZZ"
      "ck54bDQxYTJKZUNBSmJyM1VHcURsbTNtUjhSY3lDUFVYUFZieHEwb0pSZFBySmtZQ1dlQ25Q"
      "ZGNLeHhQcXVpZXg0NkVEQzBGVURITG81STZVZXJ2dDM1RHJreWh4WDh0dlg5SFN3NjZONWli"
      "cW9tbmY4Q0hmeWpNczQ5dUtNdXIza1BlRWFPeXM4UDRrRHRPa2xGNGp2cGgwNFZ4OW51MWZz"
      "dThPdW5OT050Z3VHdjdRbUYxZk1IakM3UkNwTHZRZVZWc1QzY1ZrTDdtcmNZRmtnRzZxV1Fj"
      "Mkg3cUI1NUY0WVlJUjRlY29EM05PTDlkcEtRSVVvVlZvb0YzaEUzcU5uOEhKUVBja3NBWWFu"
      "aUptZHRPUkVJb01iUmllTGlpYk5rSGFMWXVKbjNRVW9ZNnV0a21yZ2F5YzZmUmF4a1FibHRy"
      "cnI0Qkk2VzA1eEZGSXZJYjZjV0pyYTZuODVqWGpWTHhmS2F1eDF0MXF4ZVI0WVlYNW4zc3hJ"
      "akdpQmkzSnZtdENIUGZvakdoOUFZb0hkdUdoaVhBRjZnYnNoYVNydEZSVmltOWJoRlJGbkk2"
      "am1STW13M284TEJOVjNuV0IxZzdxM3FRcWZtU0hBYXJyYnE2OWp1NnRScGdnR2RUTUFpTml0"
      "QmplSWQ4T1hrdFFXZ3gyYUxRYTlPN3lEQjR0clFzc0NrZldpcnJWdUxCMGhZTmtJZmI5WW5X"
      "MzNVTE51TTRxZHR0cGZlRUV4QmQ4QzRBMFBEd1NnMEdmM05vY3ZCWHJUZFlGaUJNR05YNjdW"
      "cFRDQWJCVmxUa1hBcTluOGJzYTNiTmI5TWlwSQ==");
}

// ----------------
// -              -
// - DecodeEncode -
// -              -
// ----------------

TEST(DecodeEncode, One) {
  EXPECT_EQ(base64encode(base64decode("TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu")),
            "TWFueSBoYW5kcyBtYWtlIGxpZ2h0IHdvcmsu");
}

TEST(DecodeEncode, Two) {
  EXPECT_EQ(base64encode(base64decode("TWFuIGlzIGRpc3Rpbmd1aXNoZWQu")),
            "TWFuIGlzIGRpc3Rpbmd1aXNoZWQu");
}

TEST(DecodeEncode, Three) {
  EXPECT_EQ(
      base64encode(base64decode(
          "UEtJY3J4c1RPQjFnR2swVWlva0RxOGNES2VFOWpQTHBmbmdEVGdpNjZpdW13SzBjbVBP"
          "S2hmVXJsNDI0MXJQQmw3U3Z3SVJsUDZYa0hZSldQdmQzZVl5cksxR09qN2JwdW5NcVkx"
          "bE9MWWY5SGpETzhvWUZxeE5YOUVXd3ZlZGVhQ2VBNnZEMEF3T0J1Z2dORXBNSzNCd3FY"
          "a2lnUXlrRGxmbWtPNTI3Q3BSdFF5NXRqcUNiTkxBUGlzY0FpS3dmcU9HdXlkczYzRFdF"
          "c1NJTUhOcllRS2dMalVMNjVpWTZZbGV1dDc0dFgzeHZ0dVlhbFBqdGJnbUpwVmE2TzRj"
          "aEtIWFB2VWJiY1M5VnNrZmZmMXg5amZvQWpZcTFQS0E0TFRCSksyQUhCdEMyYzlSUjZC"
          "T3lrQ050amNVRHlzMktBU0RZVDhHZDNBNTFtQk1jRWtzR3JlZ3Q2WXFBd1lvajlSNzVj"
          "UGJxNnllWHlpVmlxN0xvNTRzU3ZZck54bDQxYTJKZUNBSmJyM1VHcURsbTNtUjhSY3lD"
          "UFVYUFZieHEwb0pSZFBySmtZQ1dlQ25QZGNLeHhQcXVpZXg0NkVEQzBGVURITG81STZV"
          "ZXJ2dDM1RHJreWh4WDh0dlg5SFN3NjZONWlicW9tbmY4Q0hmeWpNczQ5dUtNdXIza1Bl"
          "RWFPeXM4UDRrRHRPa2xGNGp2cGgwNFZ4OW51MWZzdThPdW5OT050Z3VHdjdRbUYxZk1I"
          "akM3UkNwTHZRZVZWc1QzY1ZrTDdtcmNZRmtnRzZxV1FjMkg3cUI1NUY0WVlJUjRlY29E"
          "M05PTDlkcEtRSVVvVlZvb0YzaEUzcU5uOEhKUVBja3NBWWFuaUptZHRPUkVJb01iUmll"
          "TGlpYk5rSGFMWXVKbjNRVW9ZNnV0a21yZ2F5YzZmUmF4a1FibHRycnI0Qkk2VzA1eEZG"
          "SXZJYjZjV0pyYTZuODVqWGpWTHhmS2F1eDF0MXF4ZVI0WVlYNW4zc3hJakdpQmkzSnZt"
          "dENIUGZvakdoOUFZb0hkdUdoaVhBRjZnYnNoYVNydEZSVmltOWJoRlJGbkk2am1STW13"
          "M284TEJOVjNuV0IxZzdxM3FRcWZtU0hBYXJyYnE2OWp1NnRScGdnR2RUTUFpTml0Qmpl"
          "SWQ4T1hrdFFXZ3gyYUxRYTlPN3lEQjR0clFzc0NrZldpcnJWdUxCMGhZTmtJZmI5WW5X"
          "MzNVTE51TTRxZHR0cGZlRUV4QmQ4QzRBMFBEd1NnMEdmM05vY3ZCWHJUZFlGaUJNR05Y"
          "NjdWcFRDQWJCVmxUa1hBcTluOGJzYTNiTmI5TWlwSQ==")),
      "UEtJY3J4c1RPQjFnR2swVWlva0RxOGNES2VFOWpQTHBmbmdEVGdpNjZpdW13SzBjbVBPS2hm"
      "VXJsNDI0MXJQQmw3U3Z3SVJsUDZYa0hZSldQdmQzZVl5cksxR09qN2JwdW5NcVkxbE9MWWY5"
      "SGpETzhvWUZxeE5YOUVXd3ZlZGVhQ2VBNnZEMEF3T0J1Z2dORXBNSzNCd3FYa2lnUXlrRGxm"
      "bWtPNTI3Q3BSdFF5NXRqcUNiTkxBUGlzY0FpS3dmcU9HdXlkczYzRFdFc1NJTUhOcllRS2dM"
      "alVMNjVpWTZZbGV1dDc0dFgzeHZ0dVlhbFBqdGJnbUpwVmE2TzRjaEtIWFB2VWJiY1M5VnNr"
      "ZmZmMXg5amZvQWpZcTFQS0E0TFRCSksyQUhCdEMyYzlSUjZCT3lrQ050amNVRHlzMktBU0RZ"
      "VDhHZDNBNTFtQk1jRWtzR3JlZ3Q2WXFBd1lvajlSNzVjUGJxNnllWHlpVmlxN0xvNTRzU3ZZ"
      "ck54bDQxYTJKZUNBSmJyM1VHcURsbTNtUjhSY3lDUFVYUFZieHEwb0pSZFBySmtZQ1dlQ25Q"
      "ZGNLeHhQcXVpZXg0NkVEQzBGVURITG81STZVZXJ2dDM1RHJreWh4WDh0dlg5SFN3NjZONWli"
      "cW9tbmY4Q0hmeWpNczQ5dUtNdXIza1BlRWFPeXM4UDRrRHRPa2xGNGp2cGgwNFZ4OW51MWZz"
      "dThPdW5OT050Z3VHdjdRbUYxZk1IakM3UkNwTHZRZVZWc1QzY1ZrTDdtcmNZRmtnRzZxV1Fj"
      "Mkg3cUI1NUY0WVlJUjRlY29EM05PTDlkcEtRSVVvVlZvb0YzaEUzcU5uOEhKUVBja3NBWWFu"
      "aUptZHRPUkVJb01iUmllTGlpYk5rSGFMWXVKbjNRVW9ZNnV0a21yZ2F5YzZmUmF4a1FibHRy"
      "cnI0Qkk2VzA1eEZGSXZJYjZjV0pyYTZuODVqWGpWTHhmS2F1eDF0MXF4ZVI0WVlYNW4zc3hJ"
      "akdpQmkzSnZtdENIUGZvakdoOUFZb0hkdUdoaVhBRjZnYnNoYVNydEZSVmltOWJoRlJGbkk2"
      "am1STW13M284TEJOVjNuV0IxZzdxM3FRcWZtU0hBYXJyYnE2OWp1NnRScGdnR2RUTUFpTml0"
      "QmplSWQ4T1hrdFFXZ3gyYUxRYTlPN3lEQjR0clFzc0NrZldpcnJWdUxCMGhZTmtJZmI5WW5X"
      "MzNVTE51TTRxZHR0cGZlRUV4QmQ4QzRBMFBEd1NnMEdmM05vY3ZCWHJUZFlGaUJNR05YNjdW"
      "cFRDQWJCVmxUa1hBcTluOGJzYTNiTmI5TWlwSQ==");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}
